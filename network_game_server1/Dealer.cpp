#include "Dealer.h"



Dealer::Dealer()
{
	int trump = rand() / 4 + 1;
	switch (trump)
	{
	case 1: { 
		this->trump = Suit::HEARTS;
		break;
	}
	case 2: {
		this->trump = Suit::PEAKS;
		break;
	}
	case 3: {
		this->trump = Suit::DEAMONDS;
		break;
	}
	case 4: {
		this->trump = Suit::CLUBS;
		break;
	}
	default:
		break;
	}
	Card sixC = Card(DignityCard::SIX, Suit::CLUBS, false);
	Card sixD = Card(DignityCard::SIX, Suit::DEAMONDS, false);
	Card sixH = Card(DignityCard::SIX, Suit::HEARTS, false);
	Card sixP = Card(DignityCard::SIX, Suit::PEAKS, false);

	Card sevenC = Card(DignityCard::SEVEN, Suit::CLUBS, false);
	Card sevenD = Card(DignityCard::SEVEN, Suit::DEAMONDS, false);
	Card sevenH = Card(DignityCard::SEVEN, Suit::HEARTS, false);
	Card sevenP = Card(DignityCard::SEVEN, Suit::PEAKS, false);

	Card eigthC = Card(DignityCard::EIGHT, Suit::CLUBS, false);
	Card eigthD = Card(DignityCard::EIGHT, Suit::DEAMONDS, false);
	Card eigthH = Card(DignityCard::EIGHT, Suit::HEARTS, false);
	Card eigthP = Card(DignityCard::EIGHT, Suit::PEAKS, false);


	Card nineC = Card(DignityCard::NINE, Suit::CLUBS, false);
	Card nineD = Card(DignityCard::NINE, Suit::DEAMONDS, false);
	Card nineH = Card(DignityCard::NINE, Suit::HEARTS, false);
	Card nineP = Card(DignityCard::NINE, Suit::PEAKS, false);

	Card tenC = Card(DignityCard::TEN, Suit::CLUBS, false);
	Card tenD = Card(DignityCard::TEN, Suit::DEAMONDS, false);
	Card tenH = Card(DignityCard::TEN, Suit::HEARTS, false);
	Card tenP = Card(DignityCard::TEN, Suit::PEAKS, false);


	Card jackC = Card(DignityCard::JACK, Suit::CLUBS, false);
	Card jackD = Card(DignityCard::JACK, Suit::DEAMONDS, false);
	Card jackH = Card(DignityCard::JACK, Suit::HEARTS, false);
	Card jackP = Card(DignityCard::JACK, Suit::PEAKS, false);

	Card ladyC = Card(DignityCard::LADY, Suit::CLUBS, false);
	Card ladyD = Card(DignityCard::LADY, Suit::DEAMONDS, false);
	Card ladyH = Card(DignityCard::LADY, Suit::HEARTS, false);
	Card ladyP = Card(DignityCard::LADY, Suit::PEAKS, false);

	Card kingC = Card(DignityCard::KING, Suit::CLUBS, false);
	Card kingD = Card(DignityCard::KING, Suit::DEAMONDS, false);
	Card kingH = Card(DignityCard::KING, Suit::HEARTS, false);
	Card kingP = Card(DignityCard::KING, Suit::PEAKS, false);

	Card aceC = Card(DignityCard::ACE, Suit::CLUBS, false);
	Card aceD = Card(DignityCard::ACE, Suit::DEAMONDS, false);
	Card aceH = Card(DignityCard::ACE, Suit::HEARTS, false);
	Card aceP = Card(DignityCard::ACE, Suit::PEAKS, false);

	deck.push_back(sixC);
	deck.push_back(sixD);
	deck.push_back(sixH);
	deck.push_back(sixP);

	deck.push_back(sevenC);
	deck.push_back(sevenD);
	deck.push_back(sevenH);
	deck.push_back(sevenP);

	deck.push_back(eigthC);
	deck.push_back(eigthD);
	deck.push_back(eigthH);
	deck.push_back(eigthP);

	deck.push_back(nineC);
	deck.push_back(nineD);
	deck.push_back(nineH);
	deck.push_back(nineP);

	deck.push_back(tenC);
	deck.push_back(tenD);
	deck.push_back(tenH);
	deck.push_back(tenP);

	deck.push_back(jackC);
	deck.push_back(jackD);
	deck.push_back(jackH);
	deck.push_back(jackP);

	deck.push_back(ladyC);
	deck.push_back(ladyD);
	deck.push_back(ladyH);
	deck.push_back(ladyP);

	deck.push_back(kingC);
	deck.push_back(kingD);
	deck.push_back(kingH);
	deck.push_back(kingP);

	deck.push_back(aceC);
	deck.push_back(aceD);
	deck.push_back(aceH);
	deck.push_back(aceP);

	for (int i = 0; i < deck.size(); i++) {
		if (deck[i].getSuit() == this->trump) {
			deck[i].setTrupm(true);
		}
	}

	reshuffleDeck();
}


Dealer::~Dealer()
{
	
}

vector<Card> Dealer::giveOut(int count)
{
	vector<Card> outCard;
	for (int i = 0; i < count; i++) {
		outCard.push_back(deck.back());
		deck.pop_back();
	}
	return outCard;
}

Card Dealer::giveOutOne()
{
	Card card = deck.back();
	deck.pop_back();
	return card;
}

void Dealer::reshuffleDeck()
{
	for (int i = 0; i<deck.size(); i++)
		for (int j = deck.size() - i - 1; j >= 0; j--) {
			if (j != 0) {
				int k = rand() / j + i;
				Card tmp = deck[i];
				deck[i] = deck[k];
				deck[k] = tmp;
			}
		}
}

int Dealer::leftCard()
{
	return deck.size();
}

Suit Dealer::getTrump()
{
	return trump;
}
