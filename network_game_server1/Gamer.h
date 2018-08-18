#pragma once
#pragma warning(disable:4996)
#include <vector>
#include "Card.h"

using namespace std;
class Gamer
{
private:
	int id;
	char* name;
	vector<Card>  cards;
	vector<Card> activeCards;
	bool walks;
public:
	Gamer(int id,char* name);
	Gamer();
	~Gamer();
	//Указываем ходит ли игрок или отбивается
	void setWalks(bool isWalks);

	bool isWalks();

	//кол-во карт у игрока
	int countCard();

	//Набираем карты
	void take(vector<Card> cards);

	//Ходим картой
	void selectCards(vector<Card> card);

	vector<Card> selectedCards();
};

