#ifndef __ENTITYMANAGER_H__  
#define __ENTITYMANAGER_H__  
#include "Entity.h"
#include <vector>
#include <iostream>
struct OperatorTest;
typedef std::vector<Entity*> EntityList;
class  EntityManager
{
public:
	 EntityManager();
	~EntityManager();

public:
	std::vector<Entity*> getEntityList();
	std::string getClassName()
	{
		std::cout << " ClassName EntityManager ---	!!" << std::endl;
		return "EntityManager";
	}

	unsigned int GetStaticValue()
	{
		static unsigned int a = 1;
		return ++a;
	}

	static int GetFunctionValue()
	{
		return 10;
	}

	void AddEntity(Entity* entity);
	void PrintEntityListInfo(std::string str,int a);
	void PrintEntityListInfoTest(std::string str, int a);

	void AddFuntiocnTest();

	friend struct OperatorTest;

public:
	void AddEntityPrivate(Entity* entity)
	{
		entity_list_.push_back(entity);
	}
	std::vector<Entity*> entity_list_;
};



#endif 