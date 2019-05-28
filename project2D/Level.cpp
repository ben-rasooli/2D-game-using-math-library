#include "Level.h"

Level::Level()
{
	_platform = new Platform("platform.png");
	_platform->SetParent(this);

	_collisionManager = new CollisionManager();
	_collisionManager->AddGameObject(_platform, 0);
}

Level::~Level(){}

void Level::Draw(aie::Renderer2D * renderer)
{
	GameObject::Draw(renderer);
	_collisionManager->Draw(renderer);
}
