#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	std::cout << " Entity Construct!!" << std::endl;
}

Entity::~Entity()
{
	std::cout << " Entity Destruct!!" << std::endl;
}

std::string Entity::getClassName()
{
	return "Entity";
}


std::string Entity::getTestName()
{
	return "TestName";
}


std::string Entity::GetVirtualName()
{
	return "Virtual Entity";
}