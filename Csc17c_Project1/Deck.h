#ifndef DECK_H
#define DECK_H

#include <list>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <random>
#include <stack>
#include "card.h"

class Deck
{
private:
	const int RANK_SIZE = 25;
	const int DECK_SIZE = 108;
	std::list <Card> *dDeck = new std::list <Card>; //list deck
	std::vector <Card> *sDeck = new std::vector <Card>; //shuffle deck
	std::stack <Card> *aDeck = new std::stack <Card>; //deck stack

public:
	Deck()
	{ 
		populateDeck(); 
		shuffleDeck(); 
		stackDeck(); 
	}
	~Deck()
	{ 
		delete dDeck, sDeck, aDeck; 
		dDeck, sDeck, aDeck = nullptr; 
	}
	void populateDeck();
	void showDeck();
	void shuffleDeck();
	void stackDeck();
	void discard();
	void startDiscard();
	void disAdd(Card);
	Card drawDeck();
	std::string showCol();
	int showNum();
};

#endif
