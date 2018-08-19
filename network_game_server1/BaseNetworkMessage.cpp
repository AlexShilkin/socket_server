#include "BaseNetworkMessage.h"


char * BaseNetworkMessage::maskType()
{
	char* maskType = nullptr;
	if (this->maskData != nullptr && this->maskHeader != nullptr) {
		int maskTypeLength = strlen(this->maskData) + strlen(this->maskHeader) + 1;
		maskType = new char[maskTypeLength];
		maskType[0] = '\0';
		strcat(maskType, this->maskHeader);
		strcat(maskType, this->maskData);
		strcat(maskType, " ");
		maskType[maskTypeLength] = 0;
	}
	return maskType;
}

char * BaseNetworkMessage::maskTypeHeader()
{
	char* maskType = nullptr;
	if (this->maskHeader != nullptr) {
		int maskTypeLength = strlen(this->maskHeader) + 1;
		maskType = new char[maskTypeLength];
		maskType[0] = '\0';
		strcat(maskType, this->maskHeader);
		strcat(maskType, " ");
		maskType[maskTypeLength] = 0;
	}
	return maskType;
}

char * BaseNetworkMessage::maskTypeData()
{
	char* maskType = nullptr;
	if (this->maskData != nullptr) {
		int maskTypeLength = strlen(this->maskData) + 1;
		maskType = new char[maskTypeLength];
		maskType[0] = '\0';
		strcat(maskType, this->maskData);
		strcat(maskType, " ");
		maskType[maskTypeLength] = 0;
	}
	return maskType;
}

BaseNetworkMessage::BaseNetworkMessage()
{
}


BaseNetworkMessage::~BaseNetworkMessage()
{
}

char * BaseNetworkMessage::getMessageFromNetwork()
{
	return nullptr;
}

int BaseNetworkMessage::getSizeMessageFromNetwork()
{
	return 0;
}

Message BaseNetworkMessage::getMessage()
{
	return Message();
}

NetworkMessage * BaseNetworkMessage::getNetworkMessage(int16_t type, char * data)
{
	return nullptr;
}

int BaseNetworkMessage::getType()
{
	return 0;
}
