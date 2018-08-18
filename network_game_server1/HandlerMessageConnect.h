#pragma once
#include  "NetworkBase.h"
#include "HandlerMessage.h"
#include "Client.h"
#include "Events.h"
class HandlerMessageConnect :public HandlerMessage {
private:
	Message* message;
public:
	HandlerMessageConnect(Message* message);
	~HandlerMessageConnect();
	void* action();

	unsigned char type();
};