#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <deque>
#include "Card.h"

class Player
{
private:
	std::string name;
	bool isCpu;
	bool isTurn = 0;
	std::deque <Card> *hand = new std::deque <Card>;
public:
	Player()
	{ 
		setCpu(); 
		setName(); 
	}
	~Player()
	{ 
		delete hand; 
		hand = nullptr; 
	}
	void setName();
	void setCpu();
	std::string getName();
	bool getCpu();
	bool getTurn();
	bool getEmpty();
	void setTurn();
	void setCard(Card);
	void disHand();
	void disHand(int);
	void showHand();
	void showDraw();
	Card playCard();
	Card playCard(int);
	std::string showColor(int);
	std::string showColor();
	int showNum(int);
	int showNum();
	int handSize();
};

#endif