#include "Dealer.h"

// Creates a Dealer class, which 'is-a' Player class
Dealer::Dealer() : Player()
{
}

// Similar to printPlayersHand(), but used in the beginning of the game when the dealer must leave a dealt card faced-down
void Dealer::printDealersHand() {
	Card* temp = this->hand.front();
	this->hand.pop_front();
	std::cout << "Dealer's Hand:\n*Face-down Card*" << std::endl;
	for (Card* i : this->hand) {
		std::cout << i->getRank() << " of " << i->getSuit() << std::endl;
	}
	this->hand.push_front(temp);
}