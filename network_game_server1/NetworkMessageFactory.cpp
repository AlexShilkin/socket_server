#include "NetworkMessageFactory.h"



NetworkMessageFactory::NetworkMessageFactory()
{
}


NetworkMessageFactory::~NetworkMessageFactory()
{
}

NetworkMessage * NetworkMessageFactory::createNetworkMessage(int16_t type, char * data)
{
	switch (type)
	{
	case NETWORK_MESSAGE_TYPE_ASSING: {
		AssignNetworkMessage *assignNetworkMessage = new  AssignNetworkMessage();
		assignNetworkMessage->getNetworkMessage(type, data);
		return assignNetworkMessage;
	}
	default:
		return nullptr;
	}
}
