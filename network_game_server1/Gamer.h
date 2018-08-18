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
	//��������� ����� �� ����� ��� ����������
	void setWalks(bool isWalks);

	bool isWalks();

	//���-�� ���� � ������
	int countCard();

	//�������� �����
	void take(vector<Card> cards);

	//����� ������
	void selectCards(vector<Card> card);

	vector<Card> selectedCards();
};

