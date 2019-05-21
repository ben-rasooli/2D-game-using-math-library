#pragma once
#include "GameObject.h"
#include "TankController.h"

class Level :
	public GameObject
{
public:
	Level();
	~Level();

private:
	TankController* _tankController;
};

