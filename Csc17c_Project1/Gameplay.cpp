#include "pch.h"
#include "Gameplay.h"

void Gameplay::initialize()
{
	//bs
	int choice = 0;
	int index = 0;
	//bs
	std::cout << "\nCurrent discard card" << std::endl;
	testDeck->startDiscard();
	testDeck->showDeck(); //show discard pile //come back to this only show top of pile
	std::cout << std::endl;

	//initially set turn for non cpu player
	std::deque <Player> ::iterator it;
	for (it = playerCont->begin(); it != playerCont->end(); ++it) {
		if (!it->getCpu())
			it->setTurn();
	}

	//turn logic
	for (;;) {
		for (it = playerCont->begin(); it != playerCont->end(); ++it) {
			if (it->getTurn()) {
				std::cout << "\nIt is Player " << it->getName() << "'s turn" << std::endl;
				std::cout << "Would you like to draw or play a card (1 or 2): ";
				std::cin >> choice;
				if (choice == 1) {
					deal(1);
					std::cout << "\nYou drew" << std::endl;
					it->showDraw(); //come back to this and fix to just show the draw card not whole hand
					std::cout << "\nWould you like to keep this card or play it? (1 or 2): ";
					std::cin >> choice;
					if (choice == 2) {
						it->showHand();
						dealHand->push_back(it->playCard()); //push last card aka card you drew into dealer hand
						it->disHand(); //discard the card from hand
						testDeck->disAdd(dealHand->back()); //push card to discard pile
						dealHand->pop_back(); //discard from dealer hand
						testDeck->showDeck(); //show new discard card //comeback to this just show top of discard
					}
					it->setTurn();
					if (it->getCpu())
						--it;
					else
						++it;
					it->setTurn();
				}
				else {
					it->showHand();
					std::cout << "\nWhat card do you want to play? (enter value of index of the card): ";
					std::cin >> index;
					dealHand->push_back(it->playCard(index)); // push the desired card into dealers hand
					it->disHand(index); // discard card from hand
					testDeck->disAdd(dealHand->back()); // push card to discard pile
					dealHand->pop_back(); // discard card from dealer hand
					testDeck->showDeck(); // show top of discard
					it->setTurn();
					if (it->getCpu())
						--it;
					else
						++it;
					it->setTurn();
				}
			}
		}
	}
}

void Gameplay::deal()
{
	for (int i = 0; i < 14; i++) {
		dealHand->push_back(testDeck->drawDeck());
		testDeck->discard();
	}
	
	std::deque <Player> ::iterator it;
	for (it = playerCont->begin(); it != playerCont->end(); ++it) {
		for (int i = 0; i < 7; i++) {
			it->setCard(dealHand->back());
			dealHand->pop_back();
		}
		//it->showHand(); //take out
		//std::cout << std::endl; //take out
	}
}

void Gameplay::deal(int n)
{
	//pushes cards into dealers hand, and discards from deck
	for (int i = 0; i < n; i++) {
		dealHand->push_back(testDeck->drawDeck());
		testDeck->discard();
	}

	//iterates through players finding whose turn it is, and giving the correct amount of cards to said player
	//then pops the card out of the dealers hand
	std::deque <Player> ::iterator it;
	for (it = playerCont->begin(); it != playerCont->end(); ++it) {
		if (it->getTurn()) {
			for (int i = 0; i < n; i++) {
				it->setCard(dealHand->back());
				dealHand->pop_back();
			}
		}
	}
}

void Gameplay::setScore()
{

}

void Gameplay::setPlayers()
{
	std::cout << "\nHow many players did you wish to play with today? ";
	std::cin >> nPlayers;
}

void Gameplay::setTurn()
{
	turn = 0;
}

int Gameplay::getScore()
{
	return score;
}

int Gameplay::getPlayers()
{
	return nPlayers;
}

int Gameplay::getTurn()
{
	return turn;
}