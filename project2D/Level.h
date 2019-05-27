#pragma once
#include "GameObject.h"
#include "TankController.h"
#include "Ship.h"

class Level :
	public GameObject
{
public:
	Level();
	~Level();

private:
	TankController* _tankController;
	Ship* _ship;
};

