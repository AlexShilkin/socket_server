#pragma once
#include "Message.h"
#include "SearchGame.h"

class HandlerMessageGameSearch
{
private:
	Message* message;
	SearchGame* searchGame;
public:
	HandlerMessageGameSearch(Message* message);
	~HandlerMessageGameSearch();
	void* action();

	void callback(void* param);
};

