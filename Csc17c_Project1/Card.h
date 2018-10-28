#pragma once
#include <iostream>

class Card
{
private:
	int number = 0;
	std::string color;

public:
	Card(int n)
	{ number = n; }
	~Card()
	{ std::cout << "this is the card deconstructor" << std::endl; };
	void showCard();
	enum RANK { RED, GREEN, BLUE, YELLOW, WILD = 8 };
	RANK rColor;
	void setColor(RANK);
	std::string getColor();
};
