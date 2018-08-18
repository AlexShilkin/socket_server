#include "HandlerMessageConnect.h"


/*
unsigned char version;
unsigned char flag;
int idHost;
int lengthData;
unsigned char *data;
*/

HandlerMessageConnect::HandlerMessageConnect(Message*  message)
{
	this->message = message;
}

HandlerMessageConnect::~HandlerMessageConnect()
{
	this->message = nullptr;
}

void * HandlerMessageConnect::action()
{
	Client *client=new Client();
	char* nameClient;
	nameClient = new char[message->lengthData];
	nameClient = reinterpret_cast<char *>(message->data);

	client->setId(message->idHost);
	client->setName(nameClient);
	HANDLE eventNewConnectClient = GetEventNewConnetClient();
	SetEvent(eventNewConnectClient);
	return client;
}

unsigned char HandlerMessageConnect::type()
{
	return HandlerMessage::TYPE_MESSAGE_CONNECT;
}

