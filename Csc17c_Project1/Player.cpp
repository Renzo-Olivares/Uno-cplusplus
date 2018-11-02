#include "pch.h"
#include "Player.h"

void Player::setName()
{
	if (isCpu) {
		name = "John";
		std::cout << "The CPU name is " << getName() << std::endl;
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

void Player::setCard(Card n)
{
	hand->push_back(n);
}

void Player::showHand()
{
	std::cout << "\nPlayer: " << name << " Hand" << std::endl;
	if (isCpu)
		std::cout << "Hand is hidden" << std::endl;
	else {
		std::deque <Card> ::iterator it;
		for (it = hand->begin(); it != hand->end(); ++it) {
			//it->showCard();
		}
	}
}

void Player::showDraw()
{
	std::deque <Card> ::iterator it;
	for (it = hand->end(); it <= hand->end(); ++it) {
			it->showCard();
	}//remember to fix
	//pass hand to a stack
	//push top card to new dequeu
	//iterate over that deque showing only draw card
}

void Player::disHand()
{
	hand->pop_back();
}

void Player::disHand(int n)
{
	hand->pop_back();
}

void Player::setTurn()
{
	if (isTurn)
		isTurn = 0;
	else
		isTurn = 1;
}

bool Player::getTurn()
{
	return isTurn;
}

Card Player::playCard()
{
	return hand->back();
}

Card Player::playCard(int n)
{
	return hand->at(n);
}