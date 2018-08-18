#pragma once
#include "GameState.h"
class SteepOneGamer : public GameState
{
public:
	SteepOneGamer();
	~SteepOneGamer();
	void onStart(Game* game);

	void onStop(Game* game);

	//��������� �������� ����� (������� �� state)
	void cardValidate(Game*game, Card card);

	//������ ������������ ������ �����
	void beatOffCards(Game* game, vector<Card> cards);

	//������ ������������ ������� �����
	void pickUpCards(Game* game, vector<Card> cards);

	//����� ������� 
	void gamerBeatOffCards(Game* game);

	//����� ������ �����
	void gamerPickUpCards(Game* game);
};

