#include "EntityManager.h"
#include <iostream>

EntityManager::EntityManager()
{
	std::cout << " EntityManager Construct !!" << std::endl;
}

EntityManager::~EntityManager()
{
	std::cout << " EntityManager Destruct !!" << std::endl;
}

std::vector<Entity*> EntityManager::getEntityList()
{
	return entity_list_;
}

//std::string EntityManager::getClassName()
//{
//	std::cout << " ClassName EntityManager !!" << std::endl;
//	return "EntityManager";
//}


void EntityManager::AddEntity(Entity* entity)
{
	entity_list_.push_back(entity);
}

void EntityManager::PrintEntityListInfo(std::string str, int a)
{
	for (EntityList::const_iterator itr = entity_list_.begin(); 
		itr != entity_list_.end(); ++itr)
	{
		std::cout << (*itr)->GetVirtualName() << std::endl;
	}
	std::cout << "current index:" << a << " static: " << GetStaticValue() << "-" << GetFunctionValue() << std::endl
		<< std::endl << std::endl;
}

void EntityManager::PrintEntityListInfoTest(std::string str, int a)
{
	for (EntityList::const_iterator itr = entity_list_.begin(); itr != entity_list_.end(); ++itr)
	{
		std::cout << (*itr)->getTestName() << std::endl;
	}
	std::cout << str << a << std::endl;
}

EntityManager* gEntityMgr = new EntityManager;


