#pragma once
#include <raylib.h>
#include "Entity.h"
class EntityFactory {
public:
	virtual Entity* CreateEntity() = 0;
	virtual ~EntityFactory();
};