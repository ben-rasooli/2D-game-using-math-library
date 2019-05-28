#pragma once
#include "GameObject.h"
#include "ColliderManager.h"
#include "Ship.h"
#include "Tank.h"

class Level :
	public GameObject
{
public:
	Level();
	~Level();

private:
	ColliderManager* _collisionManager;
	Ship* _ship;
	Tank* _tank;
};

