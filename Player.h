#ifndef __PLAYER_H__  
#define __PLAYER_H__  
#include <string>
#include "Entity.h"
class Player : public Entity
{
public:
	Player();
	~Player();
public:
	std::string getClassName();

	virtual std::string GetVirtualName();
};

#endif 