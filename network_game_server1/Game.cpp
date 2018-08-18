#include "Game.h"

Game::Game(Gamer gamer1, Gamer gamer2)
{
	this->gamer1 = gamer1;
	this->gamer2 = gamer2;
	this->dealer = Dealer();
}

Game::~Game()
{
}

int Game::leftCard()
{
	return dealer.leftCard();
}

Dealer Game::getDealer()
{
	return dealer;
}

Gamer Game::walkingGamer()
{
	return Gamer();
}

Gamer Game::batterGamer()
{
	return Gamer();
}

void Game::start()
{
	vector<Card> cardsGamer1;
	vector<Card> cardsGamer2;

	for (int i = 0; i < 6; i++) {
		cardsGamer1.push_back(dealer.giveOutOne());
		cardsGamer2.push_back(dealer.giveOutOne());
	}
	gamer1.take(cardsGamer1);
	gamer2.take(cardsGamer2);
}


void Game::finish()
{

}

void Game::gameloop()
{
	int state = 0;
	if (dealer.leftCard() > 0) {
//		g
	}
}

void Game::cardValidate(Card card)
{
	
}

void Game::beatOffCards(vector<Card> cards)
{
	
}

void Game::pickUpCards(vector<Card> cards)
{
	
}

void Game::gamerBeatOffCards()
{
	
}

void Game::gamerPickUpCards()
{
	
}
