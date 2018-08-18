#pragma once
#pragma warning(disable:4996)

#include "Card.h"
#include "Gamer.h"
#include <vector>

using namespace std;
class Dealer
{
private:
	vector<Card> deck;
	Suit trump;
	int countCardInDeck;
public:
	//создаем дилера, подготавливаем колоду катр и тасуем ее, выбираем козыря
	Dealer();
	~Dealer();
	//раздаем count Card
	vector<Card> giveOut(int count);
	//раздаем одну карту
	Card giveOutOne();
	//тасуем калоду
	void reshuffleDeck();
	//говорим сколько карт осталось
	int leftCard();
	//говорим какой сейчас козырь
	Suit getTrump();
};