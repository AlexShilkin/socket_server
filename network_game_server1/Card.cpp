#include "Card.h"

Card::Card(DignityCard dignity, Suit suit, bool isTrump)
{
	this->dignity = dignity;
	this->suit;
	this->trump = isTrump;
}

Card::Card()
{
}

Card::~Card()
{

}

bool Card::beats(Card card)
{
	bool isBeats = false;

	if (this->trump == true) {
		if (card.isTrump() == true) {
			if (this->dignity - card.dignity > 0) {
				isBeats = true;
			}
			else {
				isBeats = false;
			}
		}
		else {
			isBeats = true;
		}
	}
	else {
		if (this->suit == card.suit) {
			if (this->dignity - card.dignity > 0) {
				isBeats = true;
			}
			else {
				isBeats = false;
			}
		}
		else {
			isBeats = false;
		}
	}
	return isBeats;
}

void Card::setTrupm(bool isTrump)
{
	this->trump = isTrump;
}

bool Card::isTrump()
{
	return this->trump;
}

bool Card::equals(Card card)
{
	bool isEquals = false;
	if (this->suit == card.suit&&this->dignity==card.dignity) {
		isEquals = true;
	}
	return isEquals;
}

DignityCard Card::getDignity()
{
	return dignity;
}

Suit Card::getSuit()
{
	return suit;
}

char * Card::toUchars()
{
	char* uchars=new char[3];
	uchars[0] =dignity;
	uchars[1] = suit;
	uchars[2] = trump;

	return uchars;
}
