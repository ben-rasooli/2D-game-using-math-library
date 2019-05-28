#include "Level.h"

Level::Level()
{
	_ship = new Ship("platform.png");
	_ship->SetParent(this);

	//_collisionManager = new ColliderManager();
	//_collisionManager->AddGameObject(_ship);
}


Level::~Level(){}
