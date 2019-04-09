#include "Player.h"

// Creates a Player object - the main users of the game
Player::Player() {
	// Gives each created player an empty hand and an empty list of scores
	std::list<Card*> hand;
	std::list<int> scores;
	this->hand = hand;
	this->scores = scores;
}

// Gets the player's hand
std::list<Card*> Player::getHand() {
	return this->hand;
}

// Gets a list of scores possible given the player's hand
std::list<int> Player::getScores() {
	return this->scores;
}

// Calculates each possible score given the player's hand
void Player::calcScores() {
	int numAces = 0;
	int lowScore = 0;
	std::list<int> clearScores;
	this->scores = clearScores;
	// Counts the number of aces in the player's hand, as aces can be counted as either 1 or 11
	for (Card* i : this->hand) {
		if (i->getValue() == 1) {
			numAces++;
		}
		lowScore += i->getValue();
	}
	// Adds the cards in the player's hand together to get a baseline score, where each Ace is only worth 1
	this->scores.push_front(lowScore);
	// Adds a score that is 10 greater than the baseline score for any case where an Ace could be scored as 11.
	for (int j = 0; j < numAces; j++) {
		this->scores.push_back(lowScore + ((j+1) * 10));
	}
	// Removes scores greater than 21, as they are illegal
	int numScoresGreaterThan21 = 0;
	for (int k : this->scores) {
		if (k > 21) {
			numScoresGreaterThan21++;
		}
	}
	for (int m = 0; m < numScoresGreaterThan21; m++) {
		this->scores.pop_back();
	}
}

// Passes a drawn card and adds it to the player's hand, then re-calculates the player's list of possible scores
void Player::hit(Card* aCard) {
	this->hand.push_back(aCard);
	this->calcScores();
}

// Prints the contents of the player's hand
void Player::printPlayerHand() {
	std::cout << "\nHand:" << std::endl;
	for (Card* i : this->hand) {
		std::cout << i->getRank() << " of " << i->getSuit() << std::endl;
	}
	// If the player has no legal scores, displays a message that they have busted
	if (this->scores.empty() == true) {
		std::cout << "\nPossible Scores:\nNone (Busted!)" << std::endl;
	}
	// Otherwise, prints a list of the player's legal scores
	else {
		std::cout << "\nPossible Scores:" << std::endl;
		for (int i : this->scores) {
			std::cout << i << std::endl;
		}
		std::cout << "\n";
	}
}