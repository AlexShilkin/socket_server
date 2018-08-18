#pragma once
#include "Message.h"

QueueMessage* CreateQueue()
{
	QueueMessage* queueMessage=new QueueMessage();
	queueMessage->buffer = std::queue<Message>();
	return queueMessage;
}

unsigned char* CreateMessage(
	int16_t flag,
	int16_t idHost,
	int32_t lengthData,
	char *data)
{
	unsigned char *message = new unsigned char[lengthData + 10];
	int16_t version = MESSAGE_VERSION;
	int32_t packSize;
	
	packSize = pack(message, "hhlls ", 
		(int16_t)version, (int16_t)flag, (int32_t)idHost, (int32_t)lengthData, data);
	printf("pack = %d/n", packSize);
	return message;
}



Message ConvertCharsToMessage(unsigned char* message)
{
	int16_t v;
	int16_t f;
	int32_t id;
	int32_t len;
	int8_t * data = new int8_t[256];

	unpack(message, "hhlls ", &v, &f, &id, &len, data);

	printf("version = &d/n", v);
	printf("flag = &d/n", f);
	printf("id = &d/n", id);
	printf("lengthData = &d/n", len);
	printf("data = &s/n", data);

	Message messageObj;
	messageObj.version = v;
	messageObj.flag = f;
	messageObj.idHost = id;
	messageObj.lengthData = len;
	messageObj.data = data;
	return messageObj;
}



int AddMessageInQueue(Message message, QueueMessage &queueMessage)
{
	queueMessage.buffer.push(message);
	return queueMessage.buffer.size();
}


