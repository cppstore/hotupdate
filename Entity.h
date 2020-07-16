#ifndef __ENTITY_H__  
#define __ENTITY_H__
#include <string>

class Entity
{
public:
	Entity();
	~Entity();
public:
	virtual std::string getClassName();
	std::string getTestName();

	virtual std::string GetVirtualName();
};

#endif 