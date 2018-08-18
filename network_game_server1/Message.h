#pragma once
#include "Utils.h"
#include <queue>


#define MESSAGE_VERSION 1
#define MESSAGE_MESSAGE_SIZE_HEADER 10

#pragma pack(push, 1)
struct Message
{
	//header 10 byte
	int16_t version;
	int16_t flag;
	int16_t idHost;
	int32_t lengthData;
	//data lenghtData byte
	int8_t *data;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct QueueMessage
{
	std::queue<Message> buffer;
};
#pragma pack(pop)

QueueMessage* CreateQueue();

unsigned char* CreateMessage(
	int16_t flag,
	int16_t idHost,
	int32_t lengthData,
	char *data);


Message ConvertCharsToMessage(unsigned char* message);


//return size BufferMessage and added message in buffer
int  AddMessageInQueue(Message message, QueueMessage &queueMessage);

