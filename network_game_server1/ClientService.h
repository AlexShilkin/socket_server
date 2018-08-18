#pragma once
#include <vector>

#include "AsyncFile.h"
#include "Client.h"

#define path_file_clients "C:\\Users\\Светлана\\Documents\\Visual Studio 2015\\Projects\\network_game_server1\\data\\clients.txt"

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

