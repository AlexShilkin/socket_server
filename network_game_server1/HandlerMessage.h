#pragma once
#include "Message.h"
#include "HandlerMessageSignIn.h"
#include <vector>


class HandlerMessage {

public:
	//клиент отправляется серверу свое имя
	static const unsigned char TYPE_MESSAGE_SIGNIN = 1;
	//сообщение клиенту в ответ на подключение (отсылает id client)
	static const unsigned char TYPE_MESSAGE_CONNECT = 2;
	//сообщение клиенту в ответ на подключение (отсылает id client)
	static const unsigned char TYPE_MESSAGE_DISCONNECT = 3;
	//сервер оправляет клиенту его id
	static const unsigned char TYPE_MESSAGE_ASSIGN_ID_CLIENT = 4;
	//сервер оправляет данные о старте игры
	static const unsigned char TYPE_MESSAGE_GAME_START = 6;
	//сервер отправляет данные о конце игры
	static const unsigned char TYPE_MESSAGE_GAME_FINISH  = 7;
	//клиен посылает серверу сообщение о поиске игры
	static const unsigned char TYPE_MESSAGE_GAME_SEARCH_START= 9;
	//клиен посылает серверу сообщение об отмене поиска игры
	static const unsigned char TYPE_MESSAGE_GAME_SEARCH_CANCEL = 10;
	//клиент отсылает сообщение серверу о картах которыми он походил 
	static const unsigned char TYPE_MESSAGE_GAME_STEP_PLAYER = 11;
	//сообщение что карты побиты
	static const unsigned char TYPE_MESSAGE_GAME_BEATEN_CARD = 12;

	//сообщение клиенту с выданными картами 
	static const unsigned char TYPE_MESSAGE_GAME_DEAL_CARD = 13;

	//сообщение клиенту текущая колода (карты которые остались в колоде)  
	static const unsigned char TYPE_MESSAGE_GAME_CARD_DECK = 14;

	HandlerMessage() {}
	virtual ~HandlerMessage() {}
};