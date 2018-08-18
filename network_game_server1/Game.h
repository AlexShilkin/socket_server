#pragma once
#pragma warning(disable:4996)

#include "Gamer.h"
#include "Dealer.h"

class Game
{
private:
	Gamer gamer1;
	Gamer gamer2;
	Dealer dealer;
	Card trump;

public:
	Game(Gamer gamer1, Gamer gamer2);
	~Game();
	

	int leftCard();
	Dealer getDealer();
	void start();

	/////////Function depends on state////////////
	//ходящий игрок
	Gamer walkingGamer();
	//отбивающийся игрок
	Gamer batterGamer();
	//начало новой игры

	//конец игры
	void finish();

	void gameloop();

	//проверяем активную карту (зависит от state)
	void cardValidate(Card card);

	//игроку предлагается отбить карты
	void beatOffCards(vector<Card> cards);

	//игроку предлагается забрать карты
	void pickUpCards(vector<Card> cards);
	 
	//игрок отбился 
	void gamerBeatOffCards();

	//игрок забрал карты
	void gamerPickUpCards();
};

