#pragma once
#include "Message.h"
#include "BaseNetworkMessage.h"

#define FLAG_ASSING_NETWORK_MESSAGE 1
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
};

