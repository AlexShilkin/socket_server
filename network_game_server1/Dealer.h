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
	//������� ������, �������������� ������ ���� � ������ ��, �������� ������
	Dealer();
	~Dealer();
	//������� count Card
	vector<Card> giveOut(int count);
	//������� ���� �����
	Card giveOutOne();
	//������ ������
	void reshuffleDeck();
	//������� ������� ���� ��������
	int leftCard();
	//������� ����� ������ ������
	Suit getTrump();
};