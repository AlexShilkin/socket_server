#pragma once
#include "Card.h"
#include "Game.h"
#include <vector>
class GameState
{
public:
	GameState() {};
	~GameState() {};
	
	//проверяем активную карту (зависит от state)
	virtual void cardValidate(Game* game, Card card) {};

	//игроку предлагается отбить карты
	virtual void beatOffCards(Game* game, vector<Card> cards) {};

	//игроку предлагается забрать карты
	virtual void pickUpCards(Game* game, vector<Card> cards) {};

	//игрок отбился 
	virtual void gamerBeatOffCards(Game* game) {};

	//игрок забрал карты
	virtual void gamerPickUpCards(Game* game) {};
	/*
	//ходящий игрок
	virtual Gamer walkingGamer(Game* game) {};

	//отбивающийся игрок
	virtual Gamer batterGamer(Game* game) {};
*/};

