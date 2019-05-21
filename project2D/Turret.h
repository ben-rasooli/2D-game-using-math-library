#pragma once
#include "GameObject.h"
class Turret :
	public GameObject
{
public:
	Turret(const char * textureName);
	~Turret();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);
};

