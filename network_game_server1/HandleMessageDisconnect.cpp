#include "HandlerMessageDisconnect.h"


HandlerMessageDisconnect::HandlerMessageDisconnect(Message * message)
{
	this->message = message;
}

HandlerMessageDisconnect::~HandlerMessageDisconnect()
{
	this->message = nullptr;
}

void * HandlerMessageDisconnect::action()
{
	Client *client = new Client();
	char* nameClient;
	nameClient = new char[message->lengthData];
	nameClient = reinterpret_cast<char *>(message->data);

	client->setId(message->idHost);
	client->setName(nameClient);
	HANDLE eventDisconnectClient = GetEventDisconnectClient();
	SetEvent(eventDisconnectClient);
	return client;
}

void HandlerMessageDisconnect::callback(void * param)
{

}
