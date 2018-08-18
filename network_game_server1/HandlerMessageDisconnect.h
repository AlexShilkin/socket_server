#pragma once
#include  "NetworkBase.h"
#include "HandlerMessage.h"
#include "Client.h"
#include "Events.h"

class HandlerMessageDisconnect:public HandlerMessage
{
private:
	Message* message;
public:
	HandlerMessageDisconnect(Message* message);
	~HandlerMessageDisconnect();
	void* action();
	void callback(void* param);
};

