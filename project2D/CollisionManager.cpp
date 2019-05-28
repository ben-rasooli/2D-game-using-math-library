#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

void CollisionManager::Draw(aie::Renderer2D* renderer)
{
	for (int i = 0; i < _gameObjects.Count(); i++)
	{
		Collider* collider = _gameObjects[i]->GetCollider();
		Vector2 min = collider->GetMin();
		Vector2 max = collider->GetMax();
		Vector2 extend = collider->GetExtend();

		renderer->SetRenderColour(1.0f, 0.0f, 0.0f, 0.5f);
		renderer->DrawBox(min.x + extend.x, min.y + extend.y, max.x - min.x, max.y - min.y);
	}
}

void CollisionManager::AddGameObject(GameObject * gameObject, int layer)
{
	_gameObjects.PushBack(gameObject);
}
