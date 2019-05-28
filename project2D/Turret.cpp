#include "Turret.h"
#include "Input.h"

Turret::Turret(const char * textureName) : GameObject(textureName)
{
}

Turret::~Turret()
{
}

void Turret::Update(float deltaTime)
{
	aie::Input* input = aie::Input::GetInstance();

	if (input->IsKeyDown(aie::INPUT_KEY_LEFT_ALT))
		Rotate(-3.0f * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_LEFT_CONTROL))
		Rotate(3.0f * deltaTime);

	GameObject::Update(deltaTime);
}

void Turret::Draw(aie::Renderer2D * renderer)
{
	GameObject::Draw(renderer);
}
