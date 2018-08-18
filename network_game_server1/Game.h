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
	//������� �����
	Gamer walkingGamer();
	//������������ �����
	Gamer batterGamer();
	//������ ����� ����

	//����� ����
	void finish();

	void gameloop();

	//��������� �������� ����� (������� �� state)
	void cardValidate(Card card);

	//������ ������������ ������ �����
	void beatOffCards(vector<Card> cards);

	//������ ������������ ������� �����
	void pickUpCards(vector<Card> cards);
	 
	//����� ������� 
	void gamerBeatOffCards();

	//����� ������ �����
	void gamerPickUpCards();
};

