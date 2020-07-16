#ifndef __MONSTER_H__  
#define __MONSTER_H__  
#include <string>
#include "Entity.h"
class Monster : public Entity
{
public:
	Monster();
	~Monster();
public:
	std::string getClassName();

	virtual std::string GetVirtualName();
};

#endif