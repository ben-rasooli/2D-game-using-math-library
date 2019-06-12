#pragma once
#include "GameObject.h"
#include "CollisionManager.h"
#include "Platform.h"
#include "Tank.h"

class Level :
	public GameObject
{
public:
	Level();
	~Level();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

private:
	Platform* _platform;
	Tank* _tank;
};

