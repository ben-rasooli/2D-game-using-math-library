#include "Turret.h"
#include "Input.h"
#include <iostream>

Turret::Turret(const char * textureName) : GameObject(textureName)
{
	_collider = new CircleCollider(30.0f);
	CollisionManager::I()->AddGameObject(this, CollisionLayer::ITEM);
}

Turret::~Turret() {}

void Turret::Update(float deltaTime)
{
	aie::Input* input = aie::Input::GetInstance();

	//-------------------------------------
	//				Rotate
	//-------------------------------------
	if (input->IsKeyDown(aie::INPUT_KEY_LEFT_ALT))
		Rotate(-3.0f * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_LEFT_CONTROL))
		Rotate(3.0f * deltaTime);

	//-------------------------------------
	//				 Drop
	//-------------------------------------
	if (input->IsKeyDown(aie::INPUT_KEY_SPACE) && _parent)
	{
		_parent = nullptr;
		Translate(_globalTransform.getPosition() + Vector2(0, 50.0f));
	}

	GameObject::Update(deltaTime);
	// should override the GameObject._collider.SetPosition(), because my _localPosition stays zero
	_collider->SetPosition(_globalTransform.getPosition());
}

void Turret::Draw(aie::Renderer2D * renderer)
{
	GameObject::Draw(renderer);
}

void Turret::OnCollision(GameObject * other)
{
	_parent = other;
	_localTransform.setPosition(Vector2(0, 0));
}
