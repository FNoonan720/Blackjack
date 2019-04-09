#pragma once
#include "Card.h"
#include <list>
#include <iostream>

class Player
{
public:
	Player();
	std::list<Card*> getHand();
	std::list<int> getScores();
	void calcScores();
	void hit(Card* aCard);
	void printPlayerHand();
protected:
	std::list<Card*> hand;
	std::list<int> scores;
};