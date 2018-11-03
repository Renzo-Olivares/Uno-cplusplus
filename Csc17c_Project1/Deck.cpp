#include "pch.h"
#include "Deck.h"
#include <iostream>

void Deck::populateDeck()
{
	//Generate normal ranks
	for (int k = 0; k < 4; k++) {
		Card::RANK color;
		color = static_cast<Card::RANK>(k);
		int count = 0;
		for (int i = 0; i < RANK_SIZE; i++) {
			if (count > 9)
				count = 1;
			Card* cardPtr = nullptr;
			cardPtr = new Card(count);
			cardPtr->setColor((color));
			dDeck->push_back(*cardPtr);
			count++;
		}
	}

	//Generate Wild
	for (int i = 0; i < Card::WILD; i++) {
		Card* cardPtr = nullptr;
		cardPtr = new Card(100);
		cardPtr->setColor(Card::WILD);
		dDeck->push_back(*cardPtr);
	}
}

void Deck::showDeck()
{
	std::list <Card> ::iterator it;
	for (it = dDeck->begin(); it != dDeck->end(); ++it) {
		it->showCard();
	} // shows discard pile
}

void Deck::shuffleDeck()
{
	std::vector <Card> sDeck(dDeck->begin(), dDeck->end());
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(sDeck.begin(), sDeck.end(), std::default_random_engine(seed));
	std::copy(sDeck.begin(), sDeck.end(), dDeck->begin());
}

void Deck::stackDeck()
{
	for (int i = 0; i < DECK_SIZE; i++) {
		aDeck->push(dDeck->front());
		dDeck->pop_front();
	}
}

void Deck::startDiscard()
{
	dDeck->push_back(aDeck->top());
	aDeck->pop();
}

Card Deck::drawDeck()
{
	return aDeck->top();
}

std::string Deck::showCol()
{
	return dDeck->back().getColor();
}

int Deck::showNum()
{
	return dDeck->back().getNum();
}

void Deck::discard()
{
	aDeck->pop();
}

void Deck::disAdd(Card n)
{
	dDeck->push_back(n);
}