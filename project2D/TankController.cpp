#include "TankController.h"
#include "Input.h"

TankController::TankController()
{
	Tank* _tank = new Tank("tankBlue.png");
	_tank->SetParent(this);

	Turret* _turret = new Turret("barrelBlue.png");
	_turret->SetParent(this);

	_moveMaxSpeed = 10.0f;
	_accelerationRate = 10.0f;
}


TankController::~TankController(){}

void TankController::Update(float deltaTime)
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

	Translate(_velocity);
	keepInsideShip();
	
	//-------------------------------------
	//				Rotate
	//-------------------------------------
	if (input->IsKeyDown(aie::INPUT_KEY_E))
		Rotate(-3.0f * deltaTime);

	if (input->IsKeyDown(aie::INPUT_KEY_Q))
		Rotate(3.0f * deltaTime);

	GameObject::Update(deltaTime);
}

void TankController::Draw(aie::Renderer2D * renderer)
{
	GameObject::Draw(renderer);
}

void TankController::accelerateAhead(float acceleration)
{
	_velocity += (acceleration * _localTransform.forward());
}

void TankController::accelerateBehind(float acceleration)
{
	_velocity -= (acceleration * _localTransform.forward());
}

void TankController::accelerateRight(float acceleration)
{
	_velocity += (acceleration * _localTransform.right());
}

void TankController::accelerateLeft(float acceleration)
{
	_velocity -= (acceleration * _localTransform.right());
}

void TankController::reduceVelocity(Vector2 decelaratioVelocity)
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

void TankController::keepVelocityWithingRange()
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

void TankController::keepInsideShip()
{
	Vector2 localPosition = _localTransform.getPosition();
	float walkableAreaExtend = 120.0f;

	if (localPosition.x > walkableAreaExtend)
		localPosition.x = walkableAreaExtend;

	if (localPosition.x < -walkableAreaExtend)
		localPosition.x = -walkableAreaExtend;

	if (localPosition.y > walkableAreaExtend)
		localPosition.y = walkableAreaExtend;
					  
	if (localPosition.y < -walkableAreaExtend)
		localPosition.y = -walkableAreaExtend;

	_localTransform.setPosition(localPosition);
}
