#include <stdio.h>
#include <thread>
#include <future>
#include <functional>
#include <iostream>
#include <locale.h>
#include "Message.h"
#include "Events.h"
#include "AsyncFile.h"
#include "ClientService.h"
#include "NetworkMessageFactory.h"
#include "QueueNetworkMessage.h"

#pragma comment(lib, "ws2_32.lib")

#pragma warning(disable:4996)

//template 
#define MAX_COUNT_CLIENT 2

using namespace std;

//global 
WSADATA wsaData;

SOCKET listenerSocket;
SOCKET clientSocket[MAX_COUNT_CLIENT];

SOCKADDR_IN serverAddres;
SOCKADDR_IN clientsAddres[MAX_COUNT_CLIENT];

struct pollfd pollSockets[MAX_COUNT_CLIENT];


int countAcceptClient = 0;
//THREAD 
thread threadReceive;
thread threadAccept;
thread threadComputation;

unsigned int idTreadReceive;
unsigned int idThreadAccept;
unsigned int idTreadComputation;
////////
QueueNetworkMessage *queueNetworkMessage;
/////


//Service
ClientService* clientService;

void init() {
	clientService = new ClientService();
}

NetworkMessage* ReceiveMessage(SOCKET socket) {
	NetworkMessage* networkMessage;
	NetworkMessageFactory networkMessageFactory = NetworkMessageFactory();

	char *headerMessage;
	char *dataMessage;

	headerMessage = RecvData(socket, MESSAGE_MESSAGE_SIZE_HEADER);

	int16_t version;
	int16_t flag;
	int16_t idHost;
	int32_t length;
	unpack((unsigned char*)headerMessage, "hhhl ", &version, &flag, &idHost, &length);

	if (length > 0) {
		dataMessage = RecvData(socket, length);
		return networkMessageFactory.createNetworkMessage(flag, dataMessage);
	}
	
	return nullptr;
}

unsigned int ComputationThread() {
	HANDLE eventPushMessageInQueue = GetEventPushMessageInQueue();
	for (;;) {
		if (WAIT_OBJECT_0 == WaitForSingleObject(eventPushMessageInQueue, 0)) {
			NetworkMessage* networkNessage = queueNetworkMessage->pop();
			ResetEvent(eventPushMessageInQueue);
		}

	}
	return 1;
}

unsigned int ReceiveThread() {
	DWORD dwResult = 0;
	HANDLE eventNewMessage = GetEventNewMessage();
	HANDLE eventPushMessageInQueue = GetEventPushMessageInQueue();
	HANDLE eventCloseReceiveThread = GetEventCloseReceiveThread();

	for (;;) {
		if (WAIT_OBJECT_0 == WaitForSingleObject(eventCloseReceiveThread, 0)) {
			break;
		}
		// Опрашивать сокеты pool методом
		// Устанавливаем задержку 10 мс
		if (countAcceptClient > 0) {
			int eventPoll = WSAPoll(pollSockets, countAcceptClient, 10);
			if (eventPoll == -1) {
				int error = GetLastError();
				printf("WSAPoll() error: %d", error);
			}
			else if (eventPoll == 0) {
				//Not events sockets
			}
			else {
				for (int i = 0; i < countAcceptClient; i++) {
					if (pollSockets[i].revents&POLLHUP) {
						//соединение с сокетом было разорвано
						clientSocket[i] = 0;
						continue;
					}
					if (pollSockets[i].revents&POLLIN) {
						pollSockets[i].revents = 0;
						NetworkMessage* networkMessage = ReceiveMessage(pollSockets[i].fd);
						if (networkMessage != nullptr) {
							queueNetworkMessage->push(networkMessage);
							SetEvent(eventPushMessageInQueue);
						}
					}
					if (pollSockets[i].revents&POLLOUT) {
						//исходящее событие
						/*pollSockets[i].revents = 0;
						NetworkMessage* networkMessage = ReceiveMessage(pollSockets[i].fd);
						if (networkMessage != nullptr) {
							queueNetworkMessage->push(networkMessage);
							SetEvent(eventPushMessageInQueue);
						}*/
					}
				}
			}
		}
		

	}
	return dwResult;
}

unsigned int AcceptThread() {
	HANDLE eventAcceptClient = GetEventAcceptClient();
	for (;;) { 
		clientSocket[countAcceptClient] = accept(listenerSocket, NULL, NULL);
		if (clientSocket[countAcceptClient] == INVALID_SOCKET)
		{
			Print("Unable to accept");
			ReportError();
			break;
		}
		else {
			//добавляем в poll подключенный сокет
			pollSockets[countAcceptClient].fd = clientSocket[countAcceptClient];
			pollSockets[countAcceptClient].events = POLLIN;

			int16_t idClient = countAcceptClient;
			//присваеваем подключенному клиенту id и отправляем ему сообщение
			AssignNetworkMessage assignNetworkMessage = AssignNetworkMessage(idClient);
			
			SendData(clientSocket[countAcceptClient], assignNetworkMessage.getMessageFromNetwork(),assignNetworkMessage.getSizeMessageFromNetwork());
			countAcceptClient++;
			//заносим клиена в clientService
			/*Client client = Client();
			client.setId(countAcceptClient);
			clientService->addClient(client);*/
			//событие подключения нового клиента
			SetEvent(eventAcceptClient);
		}
	}
	return 0;
}


void createFile(bool isCreated) {
	if (isCreated) {
		cout << "Create file success" << endl;
	}
	else {
		cout << "Create file falied" << endl;
	}
}

void writeFile(unsigned long count) {
	cout << "write " << count << " synbol"<<endl;
}

void readFile(char *data) {
	cout << "read " << data <<endl;
}

void clearFile(bool isClear) {
	if (isClear) {
		cout << "Clear file success" << endl;
	}
	else {
		cout << "Clear file falied" << endl;
	}
}

void deleteFile(bool isDelete) {
	if (isDelete) {
		cout << "Delete file success" << endl;
	}
	else {
		cout << "Delete file falied" << endl;
	}
}

int main(void)
{	
	setlocale(LC_ALL, "");

	queueNetworkMessage = new QueueNetworkMessage();
	//init server
	init();
	initEvents();
	
	int retVal;
	
	
	Print("Init WSA2.2");
	retVal = InitWSA2(wsaData);
	
	if (retVal == SOCKET_ERROR) {
		ReportError();
	}
	else {
		Print("Init socket server");
		listenerSocket = InitSocketTSPStream();
		if (listenerSocket == INVALID_SOCKET) {
			Print("Unable to create socket");
			ReportError();
			WSACleanup();
		}
		else {
			Print("Init socket ip address and number port");
			serverAddres = InitSockAddrInet(5150, "192.168.1.56");
			
			Print("Bind ip addres whis socket server");
			retVal = BindServer(serverAddres, listenerSocket);
			if (retVal == SOCKET_ERROR) {
				Print("Unable to bind");
				ReportError();
				WSACleanup();
			}
			else {
				Print("Listener socket");
				retVal = listen(listenerSocket, 10);
				if (retVal == SOCKET_ERROR) {
					ReportError();
					WSACleanup();
				}
				else {

					//start acceptThread
					threadAccept = thread(AcceptThread);
					//start receiveThread
					threadReceive = thread(ReceiveThread); 
					//start computationThread
					threadComputation = thread(ComputationThread); 

					if (threadAccept.joinable()) {
						threadAccept.join();
					}
					if (threadReceive.joinable()) {
						threadReceive.join();
					}
					if (threadComputation.joinable()) {
						threadComputation.join();
					}


					//Закрываем сокеты
					for (int i=0;i<countAcceptClient;i++)
					closesocket(clientSocket[i]);

					closesocket(listenerSocket);

					WSACleanup();
				}
			}
		}

	}
	//endregion 
	return 0;
}