#pragma once
#include <winsock2.h>
#include <process.h>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)

//отправка подготовленных данных (данные должны заканчиваться - 0)
//возвращает кол-во отправленных данных - в случае успеха, -1 - в случае ошибки
int SendData(SOCKET socker, char *cData, int sizeData);


//прием данных 
//возвращает буффер с принятыми данными
char* RecvData(SOCKET socket, const int buflen);


//создание TCP Stream socket
SOCKET InitSocketTSPStream();


//инициализация библиотеки winsock2
//в случае ошибки больше невозможно использовать socket
int InitWSA2(WSADATA& wsaData);


//привязывание адреса к сокету
//в случае ошибки возвращает SOCKET_ERROR
int BindServer(sockaddr_in &serverAddres, SOCKET &socket);


//соединение с сервером
//в случае ошибки возвращает SOCKET_ERROR
int Connect(SOCKET clientSocket, const sockaddr* serverAddres);


//Описание возникшей ошибки
char * ReportError();


//Инициализация адреса и порта сокета
SOCKADDR_IN InitSockAddrInet(int port, char *ipAddres);