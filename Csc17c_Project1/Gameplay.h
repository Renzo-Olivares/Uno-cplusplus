#pragma once
#include "Player.h"
#include <ctime>

class Gameplay
{
private:
	std::deque <Player> *playerCont = new std::deque <Player>;
	std::list <Card> *dealHand = new std::list <Card>;
	Deck* testDeck = new Deck;
	int nPlayers;
	std::string test = "";
	std::string test2 = "";
	int num1 = 0;
	int num2 = 0;
	int index = 0;
	int choice = 0;
	int brake = 0;
	bool isValid = 0;
public:
	Gameplay()
	{
		srand(static_cast<unsigned int>(time(0)));
		setPlayers();
		for (int i = 0; i < nPlayers; i++) {
			Player* ptr = nullptr;
			ptr = new Player;
			playerCont->push_back(*ptr);
		} //Create player objects
		deal();
		initialize();
	}
	~Gameplay()
	{ 
		delete playerCont, dealHand; 
		playerCont, dealHand = nullptr; 
	}
	void initialize();
	void deal();
	void deal(int);
	void setPlayers();
	void setTurn();
	void playTurn();
	void drawTurn();
	void setValid(int, int, std::string, std::string);
	bool getValid();
	int getPlayers();
};

