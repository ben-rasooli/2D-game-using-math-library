#include "Level.h"
#include "ColliderSet.h"

Level::Level()
{
	_platform = new Platform("platform.png");
	_platform->SetParent(this);

	for (int i = 1; i < 4; i++)
	{
		Rock* rock = new Rock(Vector2(i * 150.0f, i * 100.0f));
		rock->SetParent(this);
		_rocks.PushBack(rock);
	}
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
