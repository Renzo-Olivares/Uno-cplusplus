#pragma once
#include "Player.h"

class Gameplay
{
private:
	std::list <Player> *playerCont = new std::list <Player>;
	std::list <Card> *dealHand = new std::list <Card>;
	Deck* testDeck = new Deck;
	int score;
	int nPlayers;
	int turn;
public:
	Gameplay()
	{
		setPlayers();
		initialize();
		deal();
	}
	~Gameplay()
	{ delete playerCont, dealHand; playerCont, dealHand = nullptr; }
	void initialize();
	void deal();
	void setScore();
	void setPlayers();
	void setTurn();
	int getScore();
	int getPlayers();
	int getTurn();
};

