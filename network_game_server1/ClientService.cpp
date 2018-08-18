#include "ClientService.h"



ClientService::ClientService()
{

}


ClientService::~ClientService()
{
	
}

std::vector<Client> ClientService::getClients()
{
	return this->clients;
}

Client* ClientService::getClientById(int id)
{
	for (Client client : this->clients) {
		if (client.getId() == id) {
			return &client;
		}
	}
	return nullptr;
}

Client* ClientService::getClientByName(char * name)
{
	for (Client client : this->clients) {
		if (strcmp(client.getName(),name)==0) {
			return &client;
		}
	}
	return nullptr;
}

void ClientService::addClient(Client client)
{
	this->clients.push_back(client);
}

void ClientService::removeClientById(int id)
{
	std::vector<Client> bufferClient;
	for (int i = 0; i < this->clients.size(); i++) {
		if (this->clients[i].getId() != id) {
			bufferClient.push_back(this->clients[i]);
		}
	}
	this->clients.clear();
	this->clients = bufferClient;
}
