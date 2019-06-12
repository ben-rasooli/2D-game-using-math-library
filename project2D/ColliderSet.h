#pragma once
#include "GameObject.h"
#include "../DataStructuresLib/List.h"

enum CollisionLayer
{
	DEFAULT,
	ITEM,
	TANK
};

struct ColliderSet
{
	CollisionLayer Layer;
	List<CollisionLayer> CollidableLayers;
	List<GameObject*> ColliderOwners;
};