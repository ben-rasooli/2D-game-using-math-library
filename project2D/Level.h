#pragma once
#include "GameObject.h"
#include "../DataStructuresLib/List.h"
#include "CollisionManager.h"
#include "Platform.h"
#include "Rock.h"

class Level :
	public GameObject
{
public:
	Level();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

private:
	Platform* _platform;
	List<Rock*> _rocks;
};

