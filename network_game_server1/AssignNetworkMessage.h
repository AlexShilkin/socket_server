#pragma once
#include "Message.h"
#include "BaseNetworkMessage.h"

#define NETWORK_MESSAGE_TYPE_ASSING 1
#define SERVER_ID_HOST 0


class AssignNetworkMessage : public BaseNetworkMessage
{
private:
	int16_t idClient;

public:
	AssignNetworkMessage();
	AssignNetworkMessage(int16_t idClient);
	~AssignNetworkMessage();

	char* getMessageFromNetwork();
	int getSizeMessageFromNetwork();
	NetworkMessage* getNetworkMessage(int16_t type, char* data);
	int getType();
};