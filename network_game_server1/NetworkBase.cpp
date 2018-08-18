#pragma once
#include "NetworkBase.h"
#include <stdio.h>


//������ ��� ���������
char cstrBufferMessage[512];

//�������� �������������� ������ (������ ������ ������������� - 0)
//���������� ���-�� ������������ ������ - � ������ ������, -1 - � ������ ������
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

//����� ������ 
//���������� ������ � ��������� �������
char* RecvData(SOCKET socket, const int buflen) {
	//������� ������
	cstrBufferMessage[0] = 0;

	int n = 0;
	while (n < buflen) {
		int recvd = recv(socket, cstrBufferMessage + n, buflen - n, 0);
		if (recvd < 0) {
			//������
			break;
		}
		else if (recvd == 0) {
			//���������� �������
			break;
		}
		else n += recvd;
	}
	cstrBufferMessage[n] = 0;
	return cstrBufferMessage;
}


//�������� TCP Stream socket
SOCKET InitSocketTSPStream() {
	return socket(AF_INET, SOCK_STREAM, 0);
}

//������������� ���������� winsock2
//� ������ ������ ������ ���������� ������������ socket
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

//������������ ������ � ������
//� ������ ������ ���������� SOCKET_ERROR
int BindServer(sockaddr_in &serverAddres, SOCKET &socket) {
	int error = bind(socket, (sockaddr*)&serverAddres, sizeof(serverAddres));
	return error;
}

//���������� � ��������
//� ������ ������ ���������� SOCKET_ERROR
int Connect(SOCKET clientSocket, const sockaddr* serverAddres) {
	int lenServerAddres = sizeof(serverAddres);
	return connect(clientSocket, (sockaddr*)&serverAddres, lenServerAddres);
}


//�������� ��������� ������ ��������� � �������
char* ReportError() {
	char bufferError[50]="";
	int len = sprintf_s(bufferError,50,"Error: %d\n", GetLastError());
	bufferError[len] = 0;
	return bufferError;
}



//������������� ������ � ����� ������
SOCKADDR_IN InitSockAddrInet(int port, char *ipAddres) {
	SOCKADDR_IN sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.S_un.S_addr = inet_addr(ipAddres);
	
	return sin;
}


