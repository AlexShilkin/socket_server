#include "Gamer.h"

Gamer::Gamer(int id,char* name)
{
	this->id = id;
	this->name = name;
}

Gamer::Gamer()
{
}

Gamer::~Gamer()
{
	this->cards.clear();
}

void Gamer::setWalks(bool isWalks)
{
	this->walks = isWalks;
}

bool Gamer::isWalks()
{
	return this->walks;
}

int Gamer::countCard()
{
	return this->cards.size();
}

void Gamer::take(vector<Card> cards)
{
	for (int i = 0; i < cards.size(); i++) {
		this->cards.push_back(cards[i]);
	}
}

void Gamer::selectCards(vector<Card> cards)
{
	for (int i = 0; i < cards.size(); i++) {
		int count = 0;
		for (int j = 0; j < this->cards.size(); j++) {
			if (cards[i].equals(this->cards[j])) {
				activeCards.push_back(cards[j]);
				break;
			}
		}
	}
}

vector<Card> Gamer::selectedCards()
{
	return this->activeCards;
}


