#include "Tank.h"
#include "Input.h"

Tank::Tank(const char * textureName) : GameObject(textureName)
{
}

Tank::~Tank()
{
}

void Tank::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void Tank::Draw(aie::Renderer2D * renderer)
{
	GameObject::Draw(renderer);
}
