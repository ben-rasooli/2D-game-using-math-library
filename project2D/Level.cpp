#include "Level.h"
#include "ColliderSet.h"

Level::Level()
{
	_platform = new Platform("platform.png");
	_platform->SetParent(this);
}

void Level::Update(float deltaTime)
{
	CollisionManager::I()->Update(deltaTime);
	GameObject::Update(deltaTime);
}

void Level::Draw(aie::Renderer2D * renderer)
{
	GameObject::Draw(renderer);
	CollisionManager::I()->Draw(renderer);
}
