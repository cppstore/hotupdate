#include "Monster.h"
#include "Player.h"
#include "EntityManager.h"
#include <iostream>

extern EntityManager* gEntityMgr;

//struct OperatorTest
//{
//public:
//	int a;
//	void operator()()
//	{
//		//static std::vector<int> vec;
//		//vec.push_back(3);
//		//std::cout << "OperatorTest ---  tttt:" << vec.size()  << std::endl;
//
//		for (EntityList::const_iterator itr = gEntityMgr->entity_list_.begin();
//			itr != gEntityMgr->entity_list_.end(); ++itr)
//		{
//			std::cout << "-----" << (*itr)->GetVirtualName() << "-----" << std::endl << std::endl << std::endl;
//		}
//	}
//};

std::string Monster::GetVirtualName()
{
	return "Virtual Monster Test";
}


std::string Player::GetVirtualName()
{
	return "Virtual Player Test";
}

//OperatorTest test_fun;

void EntityManager::PrintEntityListInfo(std::string str, int a)
{
	for (EntityList::const_iterator itr = entity_list_.begin();
		itr != entity_list_.end(); ++itr)
	{
		std::cout << (*itr)->GetVirtualName() << std::endl;
	}
	std::cout << "replace index4:" << a << " static: " << GetStaticValue() << "-" << GetFunctionValue()  << std::endl
		<< std::endl << std::endl;

	AddFuntiocnTest();


	getClassName();

	/*test_fun();*/
}

std::vector<int> vec;

void EntityManager::AddFuntiocnTest()
{
	vec.push_back(3);
	std::cout << "AddFuntiocnTest-" << vec.size()  << std::endl;

}




struct MyStruct
{
public:
	MyStruct()
	{
		gEntityMgr->AddEntityPrivate(new Player);
	}
};

MyStruct st;



//std::string EntityManager::getClassName()
//{
//	std::cout << " ClassName EntityManager ----!!" << std::endl;
//	return "EntityManager";
//}




//
//void test()
//{
//	OperatorTest test_fun;
//	test_fun();
//}




