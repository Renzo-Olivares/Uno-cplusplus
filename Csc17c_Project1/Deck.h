#pragma once
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
	std::list <Card> *dDeck = new std::list <Card>;
	std::vector <Card> *sDeck = new std::vector <Card>;
	std::stack <Card> *aDeck = new std::stack <Card>;

public:
	Deck()
	{ populateDeck(); shuffleDeck(); stackDeck(); }
	~Deck()
	{ std::cout << "this is the deck deconstructor" << std::endl; delete dDeck, sDeck, aDeck; dDeck, sDeck, aDeck = nullptr; }
	void populateDeck();
	void showDeck();
	void shuffleDeck();
	void stackDeck();
	void drawDeck(int);
};
