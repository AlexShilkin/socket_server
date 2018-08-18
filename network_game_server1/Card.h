#pragma once
#pragma warning(disable:4996)

enum DignityCard
{
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	LADY = 12,
	KING = 13,
	ACE = 14
};

enum Suit
{
	HEARTS = 1,
	PEAKS = 2,
	DEAMONDS = 3,
	CLUBS = 4
};
class Card
{
private:
	DignityCard dignity;
	Suit suit;
	bool trump;
public:
	Card(DignityCard dignity,Suit suit, bool isTrump);
	Card();
	~Card();
	//true - ���� ������� Card ���� �������� Card card
	bool beats(Card card);
	//������������� ������
	void setTrupm(bool isTrump);
	//�������� �� ����� ��������
	bool isTrump();
	//���������� �� �����
	bool equals(Card card);

	DignityCard getDignity();

	Suit getSuit();

	char* toUchars();
};

