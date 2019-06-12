#pragma once
#include "GameObject.h"
#include "CollisionManager.h"
#include "BoxCollider.h"

class Tank :
	public GameObject
{
public:
	Tank(const char * textureName);
	~Tank();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);
};

