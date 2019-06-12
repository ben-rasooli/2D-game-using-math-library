#include "Input.h"
#include "Platform.h"
#include <iostream>

Platform::Platform(const char * textureName) : GameObject(textureName)
{
	_tankController = new TankController();
	_tankController->SetParent(this);

	_collider = new BoxCollider(Vector2(160, 160));
	CollisionManager::I()->AddGameObject(this, CollisionLayer::DEFAULT);

	_moveMaxSpeed = 10.0f;
	_accelerationRate = 5.0f;

	_localTransform.setPosition(Vector2(700.0f, 300.0f));
}

void Platform::Update(float deltaTime)
{
	aie::Input* input = aie::Input::GetInstance();

	if (!input->IsKeyDown(aie::INPUT_KEY_UP) && !input->IsKeyDown(aie::INPUT_KEY_DOWN))
		reduceVelocity(-3 * _velocity * deltaTime);

	//-------------------------------------
	//				Translate
	//-------------------------------------
	if (input->IsKeyDown(aie::INPUT_KEY_UP))
		accelerateAhead(_accelerationRate * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_DOWN))
		accelerateBehind(_accelerationRate * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_LEFT))
		accelerateLeft(_accelerationRate * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_RIGHT))
		accelerateRight(_accelerationRate * deltaTime);

	keepVelocityWithingRange();

	//-------------------------------------
	//				Rotate
	//-------------------------------------
	if (input->IsKeyDown(aie::INPUT_KEY_RIGHT_SHIFT))
		Rotate(-1.0f * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_RIGHT_CONTROL))
		Rotate(1.0f * deltaTime);

	//-------------------------------------
	//				LookAtMouse
	//-------------------------------------
	if (input->IsKeyDown(aie::INPUT_KEY_RIGHT_ALT))
	{
		Vector2 mousePosition = 
		{
			(float)(input->GetMouseX()),
			(float)(input->GetMouseY())
		};

		Vector2 localPosition = _localTransform.getPosition();
		Vector2 directionToMouse = mousePosition - localPosition;
		directionToMouse.normalise();
		_localTransform.setRotateZ(directionToMouse);
	}

	Translate(_velocity);
	GameObject::Update(deltaTime);
}

void Platform::Draw(aie::Renderer2D * renderer)
{
	GameObject::Draw(renderer);
}

void Platform::accelerateAhead(float acceleration)
{
	_velocity += (acceleration * _localTransform.forward());
}

void Platform::accelerateBehind(float acceleration)
{
	_velocity -= (acceleration * _localTransform.forward());
}

void Platform::accelerateRight(float acceleration)
{
	_velocity += (acceleration * _localTransform.right());
}

void Platform::accelerateLeft(float acceleration)
{
	_velocity -= (acceleration * _localTransform.right());
}

void Platform::reduceVelocity(Vector2 decelaratioVelocity)
{
	if (_velocity.x > 0)
	{
		_velocity.x += decelaratioVelocity.x;
		if (_velocity.x < 0)
			_velocity.x = 0;
	}
	else if (_velocity.x < 0)
	{
		_velocity.x += decelaratioVelocity.x;
		if (_velocity.x > 0)
			_velocity.x = 0;
	}

	if (_velocity.y > 0)
	{
		_velocity.y += decelaratioVelocity.y;
		if (_velocity.y < 0)
			_velocity.y = 0;
	}
	else if (_velocity.y < 0)
	{
		_velocity.y += decelaratioVelocity.y;
		if (_velocity.y > 0)
			_velocity.y = 0;
	}
}

void Platform::keepVelocityWithingRange()
{
	if (_velocity.x > _moveMaxSpeed)
		_velocity.x = _moveMaxSpeed;

	if (_velocity.x < -_moveMaxSpeed)
		_velocity.x = -_moveMaxSpeed;

	if (_velocity.y > _moveMaxSpeed)
		_velocity.y = _moveMaxSpeed;

	if (_velocity.y < -_moveMaxSpeed)
		_velocity.y = -_moveMaxSpeed;
}
