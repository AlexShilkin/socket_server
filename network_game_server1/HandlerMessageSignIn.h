#pragma once
#include "NetworkBase.h"
#include "HandlerMessage.h"
#include "Client.h"
#include "Events.h"
class HandlerMessageSignIn
{
private:
	Message* message;
public:
	HandlerMessageSignIn(Message* message);
	~HandlerMessageSignIn();
	Client* getClientName();
	unsigned char type();
};

