#pragma once
#include <winsock2.h>
#include <process.h>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)

//�������� �������������� ������ (������ ������ ������������� - 0)
//���������� ���-�� ������������ ������ - � ������ ������, -1 - � ������ ������
int SendData(SOCKET socker, char *cData, int sizeData);


//����� ������ 
//���������� ������ � ��������� �������
char* RecvData(SOCKET socket, const int buflen);


//�������� TCP Stream socket
SOCKET InitSocketTSPStream();


//������������� ���������� winsock2
//� ������ ������ ������ ���������� ������������ socket
int InitWSA2(WSADATA& wsaData);


//������������ ������ � ������
//� ������ ������ ���������� SOCKET_ERROR
int BindServer(sockaddr_in &serverAddres, SOCKET &socket);


//���������� � ��������
//� ������ ������ ���������� SOCKET_ERROR
int Connect(SOCKET clientSocket, const sockaddr* serverAddres);


//�������� ��������� ������
char * ReportError();


//������������� ������ � ����� ������
SOCKADDR_IN InitSockAddrInet(int port, char *ipAddres);