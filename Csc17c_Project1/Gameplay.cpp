#include "pch.h"
#include "Gameplay.h"

void Gameplay::initialize()
{
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

	//Turn logic rip
	for (;;) {
		for (it = playerCont->begin(); it != playerCont->end(); ++it) {
			if (it->getTurn()) {
				std::cout << "\nIt is Player " << it->getName() << "'s turn" << std::endl;
				std::cout << "Would you like to draw or play a card (1 or 2): ";
				std::cin >> choice;
				if (choice == 1) {
					drawTurn();
					if (!getValid()) {
						std::cout << "\nThe card you drew cannot be played...end turn" << std::endl;
					}
					setTurn();
				}
				else {
					playTurn();
					if (!getValid()) {
						std::cout << "\nWould you like to try again or draw a card? (1 or 2): " << std::endl;
						if (choice == 1)
							playTurn();
						else
							drawTurn();
					}
					setTurn();
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

int Gameplay::getScore()
{
	return score;
}

int Gameplay::getPlayers()
{
	return nPlayers;
}

void Gameplay::setTurn()
{
	std::deque <Player> ::iterator it;
	for (it = playerCont->begin(); it != playerCont->end(); ++it) {
		if (it->getTurn()) {
			it->setTurn();
			if (it->getCpu())
				--it;
			else
				++it;
			it->setTurn();
		}
	}
}

void Gameplay::playTurn()
{
	std::deque <Player> ::iterator it;
	for (it = playerCont->begin(); it != playerCont->end(); ++it) {
		if (it->getTurn()) {
			it->showHand();
			std::cout << "\nWhat card do you want to play? (enter value of index of the card): ";
			std::cin >> index;
			test = it->showColor(index);
			test2 = testDeck->showCol();
			num1 = it->showNum(index);
			num2 = testDeck->showNum();
			setValid(num1, num2, test, test2);
			if (getValid()) {
				dealHand->push_back(it->playCard(index)); // push the desired card into dealers hand
				it->disHand(index); // discard card from hand
				testDeck->disAdd(dealHand->back()); // push card to discard pile
				dealHand->pop_back(); // discard card from dealer hand
				testDeck->showDeck(); // show top of discard
			}
		}
	}
}

void Gameplay::drawTurn()
{
	std::deque <Player> ::iterator it;
	for (it = playerCont->begin(); it != playerCont->end(); ++it) {
		if (it->getTurn()) {
			deal(1);
			std::cout << "\nYou drew" << std::endl;
			it->showDraw(); //come back to this and fix to just show the draw card not whole hand
			std::cout << "\nWould you like to keep this card or play it? (1 or 2): ";
			std::cin >> choice;
			if (choice == 2) {
				test = it->showColor();
				test2 = testDeck->showCol();
				num1 = it->showNum();
				num2 = testDeck->showNum();
				setValid(num1, num2, test, test2);
				if (getValid()) {
					it->showHand();
					dealHand->push_back(it->playCard()); //push last card aka card you drew into dealer hand
					it->disHand(); //discard the card from hand
					testDeck->disAdd(dealHand->back()); //push card to discard pile
					dealHand->pop_back(); //discard from dealer hand
					testDeck->showDeck(); //show new discard card //comeback to this just show top of discard
				}
			}
		}
	}
}

void Gameplay::setValid(int a, int b, std::string c, std::string d)
{
	if (a == b || c == d) {
		isValid = 1;
	}
	else
	{
		std::cout << "\nThe card you choose is invalid, pick another card or draw" << std::endl;
	}
}

bool Gameplay::getValid()
{
	return isValid;
}