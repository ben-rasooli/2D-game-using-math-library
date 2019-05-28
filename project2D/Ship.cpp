#include "Ship.h"
#include "Input.h"

Ship::Ship(const char * textureName) : GameObject(textureName)
{
	_tankController = new TankController();
	_tankController->SetParent(this);

	//_collider = new Collider(Vector2(-40, -40), Vector2(40, 40));

	_moveMaxSpeed = 10.0f;
	_accelerationRate = 10.0f;
}


Ship::~Ship() {}

void Ship::Update(float deltaTime)
{
	aie::Input* input = aie::Input::GetInstance();

	if (input->GetPressedKeys().size() == 0)
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
		Rotate(-3.0f * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_RIGHT_CONTROL))
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
