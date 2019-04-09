#pragma once
#include "Card.h"
#include <list>

class Deck
{
public:
	Deck();
	std::list<Card*> getCards();
	void fillDeck();
	void shuffleDeck();
	Card* drawCard();

private:
	std::list<Card*> cards;
};