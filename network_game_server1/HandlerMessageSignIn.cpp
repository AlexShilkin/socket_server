#include "HandlerMessageSignIn.h"



HandlerMessageSignIn::HandlerMessageSignIn(Message * message)
{
	this->message = message;
}

HandlerMessageSignIn::~HandlerMessageSignIn()
{
}

Client * HandlerMessageSignIn::getClientName()
{
	Client* client = new Client();
	client->setId(message->idHost);
	client->setName((char*)message->data);
	return client;
}

unsigned char HandlerMessageSignIn::type()
{
	return HandlerMessage::TYPE_MESSAGE_SIGNIN;
}
