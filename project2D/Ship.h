#pragma once
#include "GameObject.h"
class Ship :
	public GameObject
{
public:
	Ship();
	~Ship();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

private:
	Vector2 _velocity;
	float _moveMaxSpeed;
	float _accelerationRate;

	void accelerateAhead(float acceleration);
	void accelerateBehind(float acceleration);
	void accelerateRight(float acceleration);
	void accelerateLeft(float acceleration);
	void reduceVelocity(Vector2 decelaratioVelocity);
	void keepVelocityWithingRange();
};

