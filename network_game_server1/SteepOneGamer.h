#pragma once
#include "GameState.h"
class SteepOneGamer : public GameState
{
public:
	SteepOneGamer();
	~SteepOneGamer();
	void onStart(Game* game);

	void onStop(Game* game);

	//проверяем активную карту (зависит от state)
	void cardValidate(Game*game, Card card);

	//игроку предлагается отбить карты
	void beatOffCards(Game* game, vector<Card> cards);

	//игроку предлагается забрать карты
	void pickUpCards(Game* game, vector<Card> cards);

	//игрок отбился 
	void gamerBeatOffCards(Game* game);

	//игрок забрал карты
	void gamerPickUpCards(Game* game);
};

