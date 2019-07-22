#pragma once
#include "GameObject.h"
#include "CollisionManager.h"
#include "BoxCollider.h"

class Rock :
	public GameObject
{
public:
	Rock(Vector2 position);
	void OnCollision(GameObject* other);
};

