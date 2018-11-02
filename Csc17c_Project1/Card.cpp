#include "pch.h"
#include "Card.h"

void Card::showCard()
{
	std::cout << color << " " << number << std::endl;
}

void Card::setColor(RANK rColor)
{
	switch (rColor) {
	case RED:
		color = "Red";
		break;
	case GREEN:
		color = "Green";
		break;
	case BLUE:
		color = "Blue";
		break;
	case YELLOW:
		color = "Yellow";
		break;
	case WILD:
		color = "Wild";
		break;
	}
}

std::string Card::getColor()
{
	return color;
}

int Card::getNum()
{
	return number;
}