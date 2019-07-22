#pragma once
#include "GameObject.h"
#include "Tank.h"
#include "Turret.h"

class TankController :
	public GameObject
{
public:
	TankController();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

private:
	Tank* _tank;
	Turret* _turret;
	Vector2 _velocity;
	float _moveMaxSpeed;
	float _accelerationRate;

	void accelerateAhead(float acceleration);
	void accelerateBehind(float acceleration);
	void accelerateRight(float acceleration);
	void accelerateLeft(float acceleration);
	void reduceVelocity(Vector2 decelaratioVelocity);
	void keepVelocityWithingRange();
	void keepInsideShip();
};

