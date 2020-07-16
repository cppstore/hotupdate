#include "Player.h"
#include <iostream>

Player::Player()
{
	std::cout << " Player Construct !!" << std::endl;
}

Player::~Player()
{
	std::cout << " Player Destruct !!" << std::endl;

}

std::string Player::getClassName()
{
	return "Player";
}


std::string Player::GetVirtualName()
{
	return "Virtual Player";
}