#pragma once
#include <string>
#include <deque>

class Player
{
private:
	std::string name;
	bool isCpu;
	std::deque <Card> *hand = new std::deque <Card>;
public:
	Player()
	{ setCpu(); setName(); }
	~Player()
	{ delete hand; hand = nullptr; }
	void setName();
	void setCpu();
	std::string getName();
	bool getCpu();
	void setCard(Card n);
	void showHand();
};