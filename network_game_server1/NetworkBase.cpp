#pragma once
#include "NetworkBase.h"
#include <stdio.h>


//буфера для сообщений
char cstrBufferMessage[512];

//отправка подготовленных данных (данные должны заканчиваться - 0)
//возвращает кол-во отправленных данных - в случае успеха, -1 - в случае ошибки
int SendData(SOCKET socker, char *cData, int sizeData) {
	//int len = strlen(cData) + 1;
	int n = 0;
	int ret = 0;
	while (n < sizeData) {
		int s = send(socker, cData + n, sizeData - n, 0);
		if (s < 0) {
			ret = -1;
			break;
		}
		n += s;
	}
	return n;
}

//прием данных 
//возвращает буффер с принятыми данными
char* RecvData(SOCKET socket, const int buflen) {
	//очищаем буффер
	cstrBufferMessage[0] = 0;

	int n = 0;
	while (n < buflen) {
		int recvd = recv(socket, cstrBufferMessage + n, buflen - n, 0);
		if (recvd < 0) {
			//ошибка
			break;
		}
		else if (recvd == 0) {
			//соединение закрыто
			break;
		}
		else n += recvd;
	}
	cstrBufferMessage[n] = 0;
	return cstrBufferMessage;
}


//создание TCP Stream socket
SOCKET InitSocketTSPStream() {
	return socket(AF_INET, SOCK_STREAM, 0);
}

//инициализация библиотеки winsock2
//в случае ошибки больше невозможно использовать socket
int InitWSA2(WSADATA &wsaData) {
	WORD sockVersion;
	
	int retValue;

	sockVersion = MAKEWORD(2, 2);

	retValue = WSAStartup(sockVersion, &wsaData);
	if (retValue != 0) {
		WSACleanup();
	}
	return retValue;
}

//привязывание адреса к сокету
//в случае ошибки возвращает SOCKET_ERROR
int BindServer(sockaddr_in &serverAddres, SOCKET &socket) {
	int error = bind(socket, (sockaddr*)&serverAddres, sizeof(serverAddres));
	return error;
}

//соединение с сервером
//в случае ошибки возвращает SOCKET_ERROR
int Connect(SOCKET clientSocket, const sockaddr* serverAddres) {
	int lenServerAddres = sizeof(serverAddres);
	return connect(clientSocket, (sockaddr*)&serverAddres, lenServerAddres);
}


//Описание возникшей ошибки выводится в консоль
char* ReportError() {
	char bufferError[50]="";
	int len = sprintf_s(bufferError,50,"Error: %d\n", GetLastError());
	bufferError[len] = 0;
	return bufferError;
}



//Инициализация адреса и порта сокета
SOCKADDR_IN InitSockAddrInet(int port, char *ipAddres) {
	SOCKADDR_IN sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.S_un.S_addr = inet_addr(ipAddres);
	
	return sin;
}


