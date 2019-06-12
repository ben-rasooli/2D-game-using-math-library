#pragma once
#include "Collider.h"
#include "ColliderSet.h"
#include "GameObject.h"
#include "Renderer2D.h"
#include "../DataStructuresLib/List.h"

class CollisionManager
{
public:
	~CollisionManager();

	static CollisionManager* I();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

	void AddGameObject(GameObject* gameObject, CollisionLayer layer);

private:
	CollisionManager();
	static CollisionManager* _inst;
	List<ColliderSet*> _colliderSets;
};

