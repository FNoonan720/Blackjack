#include "Card.h"

// Creates a Card object, each with a suit, rank, and value
Card::Card(std::string suit, std::string rank, int value)
{
	this->suit = suit;
	this->rank = rank;
	this->value = value;
}

// Gets the suit of the card
std::string Card::getSuit() {
	return this->suit;
}

// Gets the rank of the card
std::string Card::getRank() {
	return this->rank;
}

// Gets the value of the card
int Card::getValue() {
	return this->value;
}