#include "Level.h"

Level::Level()
{
	_tankController = new TankController();
	_tankController->SetParent(this);
}


Level::~Level(){}
