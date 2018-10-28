#include "pch.h"
#include "Player.h"

void Player::setName()
{
	if (isCpu) {
		name = "John";
		std::cout << "This CPU name is " << getName() << std::endl;
	}
	else {
		std::cout << "Please enter your desired name: ";
		std::cin >> name;
		std::cout << "Player name is " << getName() << std::endl;
	}
}

void Player::setCpu()
{
	char choice;
	std::cout << "\nIs this player a cpu? (y or n) ";
	std::cin >> choice;
	if (choice == 'y')
		isCpu = 1;
	else
		isCpu = 0;
}

std::string Player::getName()
{
	return name;
}

bool Player::getCpu()
{
	return isCpu;
}