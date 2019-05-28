#pragma once
#include "Collider.h"
#include "GameObject.h"
#include "Renderer2D.h"
#include "../DataStructuresLib/List.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void Draw(aie::Renderer2D* renderer);

	void AddGameObject(GameObject* gameObject, int layer);

private:
	List<GameObject*> _gameObjects;
};

