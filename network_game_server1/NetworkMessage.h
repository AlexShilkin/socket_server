#pragma once
#include "Message.h"

using namespace std;

class NetworkMessage
{
protected:
	char* data;
	int length;
	char* maskHeader;
	char* maskData;

public:
	virtual ~NetworkMessage() = 0 {};
	virtual char* getMessageFromNetwork() = 0;
	virtual int getSizeMessageFromNetwork() = 0;
	virtual NetworkMessage* getNetworkMessage(int16_t type, char* data) = 0;
};

