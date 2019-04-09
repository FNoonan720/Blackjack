#pragma once
#include <string>

class Card
{
public:
	Card(std::string suit, std::string rank, int value);
	std::string getSuit();
	std::string getRank();
	int getValue();

private:
	std::string suit;
	std::string rank;
	int value;
};