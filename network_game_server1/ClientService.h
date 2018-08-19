#pragma once
#include <vector>

#include "Client.h"


class ClientService
{
private:
	std::vector<Client> clients;
public:
	ClientService();
	~ClientService();
	std::vector<Client> getClients();
	Client* getClientById(int id);
	Client* getClientByName(char* name);
	void addClient(Client client);
	void removeClientById(int id);
};

