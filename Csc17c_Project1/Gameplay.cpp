#include "pch.h"
#include "Gameplay.h"

void Gameplay::initialize()
{
	for (int i = 0; i < nPlayers; i++) {
		Player* ptr = nullptr;
		ptr = new Player;
		playerCont->push_back(*ptr);
	} //Create player objects
	std::cout << "\nCurrent discard card" << std::endl;
	testDeck->startDiscard();
	testDeck->showDeck(); //show discard pile
	std::cout << std::endl;

	/*
	//start of bullshit
	std::cout << "Player it is your turn";
	std::cout << "Would you like to draw or play a card (1 or 2)";

	if (choice == 1) {
		//draw a card
		//discard from stack
		std::cout << "Would you like to play this card?, or end your turn (1 or 2)";
		if (choice == 1) {
			//place card in discard
			//pop from hand
		}
		else {
			//move to next player's turn
		}
	}
	else {
		std::cout << "What card do you want to play? (enter value of index of the card)";
		//discard card from deque into discard
		//pop out of deque
		//move to next player's turn
	}*/  //save for later
}

void Gameplay::deal()
{
	for (int i = 0; i < 14; i++) {
		dealHand->push_back(testDeck->drawDeck());
		testDeck->discard();
	}
	
	std::list <Player> ::iterator it;
	for (it = playerCont->begin(); it != playerCont->end(); ++it) {
		for (int i = 0; i < 7; i++) {
			it->setCard(dealHand->back());
			dealHand->pop_back();
		}
		it->showHand();
		std::cout << std::endl;
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


