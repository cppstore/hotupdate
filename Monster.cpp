#include "Monster.h"
#include <iostream>

Monster::Monster()
{
	std::cout << " Monster Construct !!" << std::endl;
}

Monster::~Monster()
{
	std::cout << " Monster Destruct !!" << std::endl;

}

std::string Monster::getClassName()
{
	return "Monster";
}

std::string Monster::GetVirtualName()
{
	return "Virtual Monster";
}