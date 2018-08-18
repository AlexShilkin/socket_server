#pragma once
#include "NetworkMessage.h"
#include "AssignNetworkMessage.h"

#define NETWORK_MESSAGE_TYPE_ASSING 1


class NetworkMessageFactory
{
public:
	NetworkMessageFactory();
	~NetworkMessageFactory();

	NetworkMessage* createNetworkMessage(int16_t type, char* data);
};

