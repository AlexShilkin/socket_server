#include "AssignNetworkMessage.h"


AssignNetworkMessage::AssignNetworkMessage()
{
	this->maskHeader = "hhhl";
	this->maskData = "h";
}

AssignNetworkMessage::AssignNetworkMessage(int16_t idClient)
{
	this->maskHeader = "hhhl";
	this->maskData = "h";

	unsigned char* bufferReturn;
	unsigned char buffer[4];
	int16_t packSize;

	printf("Create AssignNetworkMessage( idClient = %hu )", idClient);

	packSize = pack(buffer, this->maskData, (int16_t)idClient);
	if (packSize > 0) {
		bufferReturn = new unsigned char[MESSAGE_MESSAGE_SIZE_HEADER + packSize];
		packSize = pack(bufferReturn, maskType(),
			(int16_t)MESSAGE_VERSION,
			(int16_t)NETWORK_MESSAGE_TYPE_ASSING,
			(int16_t)SERVER_ID_HOST,
			(int32_t)sizeof(int16_t),
			idClient);
		printf("AssignNetworkMessage message size = %d", packSize);
	}

	if (packSize > MESSAGE_MESSAGE_SIZE_HEADER) {
		this->length = packSize;
		this->data = new char[packSize];
		memcpy(this->data, (char*)bufferReturn, packSize);
	}
	else {
		length = 0;
		this->data = nullptr;
	}
	delete bufferReturn;
}

AssignNetworkMessage::~AssignNetworkMessage()
{
	delete this->data;
}

char * AssignNetworkMessage::getMessageFromNetwork()
{
	return this->data;
}

int AssignNetworkMessage::getSizeMessageFromNetwork()
{
	return length;
}

NetworkMessage* AssignNetworkMessage::getNetworkMessage(int16_t type, char* data)
{
	int16_t clientId;
	unpack((unsigned char*)data, maskTypeData(), &clientId);
	AssignNetworkMessage* assingNetworkMessage = new AssignNetworkMessage(clientId);
	return assingNetworkMessage;
}

int AssignNetworkMessage::getType()
{
	return NETWORK_MESSAGE_TYPE_ASSING;
}

