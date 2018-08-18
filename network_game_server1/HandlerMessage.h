#pragma once
#include "Message.h"
#include "HandlerMessageSignIn.h"
#include <vector>


class HandlerMessage {

public:
	//������ ������������ ������� ���� ���
	static const unsigned char TYPE_MESSAGE_SIGNIN = 1;
	//��������� ������� � ����� �� ����������� (�������� id client)
	static const unsigned char TYPE_MESSAGE_CONNECT = 2;
	//��������� ������� � ����� �� ����������� (�������� id client)
	static const unsigned char TYPE_MESSAGE_DISCONNECT = 3;
	//������ ��������� ������� ��� id
	static const unsigned char TYPE_MESSAGE_ASSIGN_ID_CLIENT = 4;
	//������ ��������� ������ � ������ ����
	static const unsigned char TYPE_MESSAGE_GAME_START = 6;
	//������ ���������� ������ � ����� ����
	static const unsigned char TYPE_MESSAGE_GAME_FINISH  = 7;
	//����� �������� ������� ��������� � ������ ����
	static const unsigned char TYPE_MESSAGE_GAME_SEARCH_START= 9;
	//����� �������� ������� ��������� �� ������ ������ ����
	static const unsigned char TYPE_MESSAGE_GAME_SEARCH_CANCEL = 10;
	//������ �������� ��������� ������� � ������ �������� �� ������� 
	static const unsigned char TYPE_MESSAGE_GAME_STEP_PLAYER = 11;
	//��������� ��� ����� ������
	static const unsigned char TYPE_MESSAGE_GAME_BEATEN_CARD = 12;

	//��������� ������� � ��������� ������� 
	static const unsigned char TYPE_MESSAGE_GAME_DEAL_CARD = 13;

	//��������� ������� ������� ������ (����� ������� �������� � ������)  
	static const unsigned char TYPE_MESSAGE_GAME_CARD_DECK = 14;

	HandlerMessage() {}
	virtual ~HandlerMessage() {}
};