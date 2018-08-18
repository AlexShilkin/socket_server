#pragma once
#include "Client.h"
#include "Game.h"
#include "Gamer.h"
#include "Dealer.h"
class SearchGame
{
private:
	int countClient = 0;
	Client* client1;
	Client* client2;
	Game* game;
	Dealer* dealer;
public:
	SearchGame();
	~SearchGame();
	void startGame();
	void addClient(Client client);
	void removeClient(Client client);
};

