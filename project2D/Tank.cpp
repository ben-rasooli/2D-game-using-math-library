#include "Tank.h"
#include "Input.h"

Tank::Tank(const char * textureName) : GameObject(textureName)
{
	_collider = new BoxCollider(Vector2(38, 37));
	CollisionManager::I()->AddGameObject(this, CollisionLayer::TANK);
}

void Tank::Update(float deltaTime)
{
	aie::Input* input = aie::Input::GetInstance();

	//-------------------------------------
	//				  Scale
	//-------------------------------------
	if (input->IsKeyDown(aie::INPUT_KEY_1))
		_localTransform.setScale(1.0f, 1.0f);
	else if (input->IsKeyDown(aie::INPUT_KEY_2))
		_localTransform.setScale(2.0f, 1.5f);
	else if (input->IsKeyDown(aie::INPUT_KEY_3))
		_localTransform.setScale(1.5f, 2.0f);

	GameObject::Update(deltaTime);
	// should override the GameObject._collider.SetPosition(), because my _localPosition stays zero
	_collider->SetPosition(_globalTransform.getPosition());
}
