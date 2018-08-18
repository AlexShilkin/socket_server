#include "SearchGame.h"



SearchGame::SearchGame()
{
	client1 = nullptr;
	client2 = nullptr;
	game = nullptr;
}


SearchGame::~SearchGame()
{
	client1 = nullptr;
	client2 = nullptr;
	game = nullptr;
}

void SearchGame::startGame()
{
	if (client1 != nullptr&&client2!=nullptr) {
		dealer = new Dealer();

		Gamer gamer1 = Gamer(client1->getId(),client1->getName());
		Gamer gamer2 = Gamer(client2->getId(),client2->getName());
		game = new Game(gamer1, gamer2);
		game->start();
	}
}

void SearchGame::addClient(Client client)
{
	if (countClient == 0) {
		client1 = &client;
		countClient++;
	}
	else if (countClient == 1) {
		client2 = &client;
		countClient++;
	}
}

void SearchGame::removeClient(Client client)
{
	if (countClient == 1) {
		if (client.getId() == client1->getId()) {
			client1 = nullptr;
			countClient--;
		}
		else if (client.getId() == client2->getId()) {
			client2 = nullptr;
			countClient--;
		}
	}
}

