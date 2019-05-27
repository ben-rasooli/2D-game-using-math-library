#include "Ship.h"
#include "Input.h"


Ship::Ship()
{
}


Ship::~Ship()
{
}

void Ship::Update(float deltaTime)
{
	aie::Input* input = aie::Input::GetInstance();

	if (input->GetPressedKeys().size() == 0)
		reduceVelocity(-3 * _velocity * deltaTime);

	//-------------------------------------
	//				Translate
	//-------------------------------------
	if (input->IsKeyDown(aie::INPUT_KEY_W))
		accelerateAhead(_accelerationRate * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_S))
		accelerateBehind(_accelerationRate * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_A))
		accelerateLeft(_accelerationRate * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_D))
		accelerateRight(_accelerationRate * deltaTime);

	keepVelocityWithingRange();

	//-------------------------------------
	//				Rotate
	//-------------------------------------
	if (input->IsKeyDown(aie::INPUT_KEY_E))
		Rotate(-3.0f * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_Q))
		Rotate(3.0f * deltaTime);

	Translate(_velocity);
	GameObject::Update(deltaTime);
}

void Ship::Draw(aie::Renderer2D * renderer)
{
	GameObject::Draw(renderer);
}

void Ship::accelerateAhead(float acceleration)
{
	_velocity += (acceleration * _localTransform.forward());
}

void Ship::accelerateBehind(float acceleration)
{
	_velocity -= (acceleration * _localTransform.forward());
}

void Ship::accelerateRight(float acceleration)
{
	_velocity += (acceleration * _localTransform.right());
}

void Ship::accelerateLeft(float acceleration)
{
	_velocity -= (acceleration * _localTransform.right());
}

void Ship::reduceVelocity(Vector2 decelaratioVelocity)
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

void Ship::keepVelocityWithingRange()
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
