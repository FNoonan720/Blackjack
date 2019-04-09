#include "Dealer.h"
#include "Deck.h"
#include <iostream>

int main() {

	// Introduces user to the game and waits for the user to press 'Enter' to begin
	std::cout << "Welcome to Frankie Noonan's Blackjack Table. Press 'Enter' to begin" << std::endl;
	std::string begin;
	std::getline(std::cin, begin);

	std::cout << "Shuffling Deck...\n\nDealing Cards...\n" << std::endl;

	// Creates a new Deck object, fills the Deck object with Card objects, then shuffles the Card objects within the Deck object
	Deck* deck = new Deck();
	deck->fillDeck();
	deck->shuffleDeck();

	// Creates the Dealer & Player objects
	Dealer* dealer = new Dealer();
	Player* player = new Player();

	// Deals two cards to both the Dealer and the Player
	dealer->hit(deck->drawCard());
	player->hit(deck->drawCard());
	dealer->hit(deck->drawCard());
	player->hit(deck->drawCard());

	// Shows the contents of the player's hand and *partially* shows the contents of the dealer's hand
	dealer->printDealersHand();
	player->printPlayerHand();

	// Initializes the final scores for both the dealer and the player as 0 for comparison upon games completion
	int playerScore = 0;
	int dealerScore = 0;

	// Creates a boolean to determine whether or not the game is completed
	bool playing = true;
	// Creates a boolean to determine whether or not the player's turn is completed
	bool playersTurn = true;

	// If the player is dealt Blackjack, the game is over and the player wins
	if (player->getScores().back() == 21) {
		std::cout << "Blackjack! You win!" << std::endl;
		playing = false;
	}

	// While the game is still being played...
	while (playing == true) {
		// While the player's turn is still being played...
		while (playersTurn == true) {
			// Creates a menu for the player to choose whether or not they want to 'Hit' or 'Stand'
			int option = 0;
			while (option != -1) {
				std::cout << "Select an option:\n1 - Hit\n2 - Stand\n" << std::endl;
				std::cin >> option;
				
				// If the player chooses to 'Hit'...
				if (option == 1) {
					// Draws a card from the top of the deck and saves it temporarily
					Card* drawnCard = deck->drawCard();
					// Shows the user which card they've drawn
					std::cout << "\nYou've drawn a(n) " << drawnCard->getRank() << " of " << drawnCard->getSuit() << "." << std::endl;
					// Adds the drawn card to the player's hand
					player->hit(drawnCard);
					// Prints the contents of the player's hand
					player->printPlayerHand();
					// Checks to see if the player has any possible (below 22) scores
					if (player->getScores().empty()) {
						// Displays a message saying that the player has busted and that the Dealer has won
						std::cout << "\nYou've busted. The Dealer wins." << std::endl;
						// Ends the player's turn, then the game, then breaks
						playersTurn = false;
						playing = false;
						break;
					}
				}
				// If the player chooses to 'Stand'...
				else if (option == 2) {
					// Sets the player's final score as their highest possible score given their hand
					playerScore = player->getScores().back();
					// Displays a message saying that the player has chosen to stand along with their final score.
					std::cout << "\nYou stand.\n\nYour score is " << playerScore << ". Let's see the Dealer's hand.\n\nFlipping face-down card..." << std::endl;
					// Ends the player's turn
					playersTurn = false;
					option = -1;
				}
			}
			// If the player won with Blackjack or busted, skips the dealer's turn
			if (playing == false) {
				break;
			}
			// If the player has not yet won/lost, begins the dealer's turn
			else {
				// Shows the dealer's full hand, including the previously faced-down card
				dealer->printPlayerHand();
				// If the dealer has busted, displays a message and ends the game
				if (dealer->getScores().empty()) {
					std::cout << "\nThe Dealer busted. You win!" << std::endl;
					playing = false;
					break;
				}
				// If the dealer has Blackjack, displays a message and ends the game
				if (dealer->getScores().back() == 21) {
					std::cout << "The Dealer has Blackjack! You lose!" << std::endl;
					playing = false;
					break;
				}
				// Otherwise, the dealers temporary final score is their best possible score at the moment
				dealerScore = dealer->getScores().back();
				// Since the dealer must hit until their max score is >=17, deals cards to Dealer's hand until said condition is met
				while (dealerScore < 17) {
					// Draws a card from the top of the deck and saves it temporarily
					Card* drawnCard = deck->drawCard();
					// Shows the user which card they've drawn
					std::cout << "The Dealer has drawn a(n) " << drawnCard->getRank() << " of " << drawnCard->getSuit() << "." << std::endl;
					// Adds the drawn card to the dealer's hand, then prints the contents of the dealer's hand
					dealer->hit(drawnCard);
					dealer->printPlayerHand();
					// If the dealer has busted, displays a message and ends the game
					if (dealer->getScores().empty()) {
						std::cout << "\nThe Dealer busted. You win!" << std::endl;
						playing = false;
						break;
					}
					// If not, saves their best possible score as their final score
					else {
						dealerScore = dealer->getScores().back();
					}
				}
				// If the game has already been ended, does not compare the player's and dealer's final scores
				if (playing == false) {
					break;
				}
			} 

			// Displays the final score of the player and the dealer
			std::cout << "Your score:\t" << playerScore << "\nDealer's Score:\t" << dealerScore << "\n" << std::endl;
			// If the player's score is higher, the player wins
			if (playerScore > dealerScore) {
				std::cout << "You win!" << std::endl;
			}
			// If the dealer's score is higher, the dealer wins
			else if (playerScore < dealerScore) {
				std::cout << "The Dealer wins!" << std::endl;
			}
			// If the scores are equal, the game is called a push
			else {
				std::cout << "It's a push!" << std::endl;
			}
		}
		// Ends the game
		playing = false;
	}

	// Allows for game window to stay open upon completion of the program
	int a;
	std::cin >> a;
}