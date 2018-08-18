#pragma once
#include "Card.h"
#include "Game.h"
#include <vector>
class GameState
{
public:
	GameState() {};
	~GameState() {};
	
	//��������� �������� ����� (������� �� state)
	virtual void cardValidate(Game* game, Card card) {};

	//������ ������������ ������ �����
	virtual void beatOffCards(Game* game, vector<Card> cards) {};

	//������ ������������ ������� �����
	virtual void pickUpCards(Game* game, vector<Card> cards) {};

	//����� ������� 
	virtual void gamerBeatOffCards(Game* game) {};

	//����� ������ �����
	virtual void gamerPickUpCards(Game* game) {};
	/*
	//������� �����
	virtual Gamer walkingGamer(Game* game) {};

	//������������ �����
	virtual Gamer batterGamer(Game* game) {};
*/};

