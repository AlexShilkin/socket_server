#include "HandlerMessageGameSearch.h"



HandlerMessageGameSearch::HandlerMessageGameSearch(Message* message)
{
	this->message = message;
	this->searchGame = new SearchGame();

}

HandlerMessageGameSearch::~HandlerMessageGameSearch()
{
}

void* HandlerMessageGameSearch::action()
{
	Client client = Client();
	client.setId(this->message->idHost);
	client.setName(reinterpret_cast<char *>(this->message->data));
	this->searchGame->addClient(client);
	return &client;
}

void HandlerMessageGameSearch::callback(void* param)
{

}
