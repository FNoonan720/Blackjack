#include "Deck.h"
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>

// Creates a Deck that includes an empty list of Card objects
Deck::Deck() {
	std::list<Card*> emptyDeckOfCards;
	this->cards = emptyDeckOfCards;
}

// Gets the contents of the deck in list<Card*> form
std::list<Card*> Deck::getCards() {
	return this->cards;
}

// Creates 52 preset Card objects and adds them to the deck
void Deck::fillDeck() {
	// Map used when giving suits to Card objects
	std::map<int, std::string> suits;
	suits[0] = "Hearts";
	suits[1] = "Diamonds";
	suits[2] = "Clubs";
	suits[3] = "Spades";

	// Map used when giving ranks to Card objects
	std::map<int, std::string> ranks;
	for (int i = 2; i <= 10; i++) {
		ranks[i] = std::to_string(i);
	}
	ranks[1]  = "Ace";
	ranks[11] = "Jack";
	ranks[12] = "Queen";
	ranks[13] = "King";

	// Map used when giving values to Card objects
	std::map<std::string, int> values;
	for (int i = 2; i <= 10; i++) {
		values[std::to_string(i)] = i;
	}
	values["Ace"] = 1;
	values["Jack"] = 10;
	values["Queen"] = 10;
	values["King"] = 10;

	// Adds each possible card to the deck (size: 52)
	std::list<Card*> cardList;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			this->cards.push_back(new Card(suits[i], ranks[j], values[ranks[j]]));
		}
	}
}

// Copies the contents of the deck into a vector to be shuffled, then added back to the deck
void Deck::shuffleDeck() {
	// Creates a vector copy of the card list
	std::vector<Card*> copy;
	for (Card* i : this->cards) {
		copy.push_back(i);
	}
	
	// Shuffles the vector of Cards
	std::srand(unsigned(time(0)));
	std::random_shuffle(copy.begin(), copy.end());

	// Replaces the initial list of cards with the shuffled order
	std::list<Card*> temp;
	for (Card* k : copy) {
		temp.push_back(k);
	}

	// Saves the shuffled version as the Deck's card list as 
	this->cards = temp;
}

// Gets the top card from the deck
Card* Deck::drawCard() {
	Card* temp;
	temp = this->cards.back();
	this->cards.pop_back();
	return temp;
}