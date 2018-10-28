#include "pch.h"
#include "Gameplay.h"

void Gameplay::initialize()
{
	//Deck* testDeck =  new Deck; //initialize deck
	//debug for me testDeck.showDeck(); //test deck
	for (int i = 0; i < nPlayers; i++) {
		Player* ptr = nullptr;
		ptr = new Player;
		playerCont->push_back(*ptr);
	} //Create player objects
}

void Gameplay::deal()
{
	//dealHand->push_back(testDeck->drawDeck(7));
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


