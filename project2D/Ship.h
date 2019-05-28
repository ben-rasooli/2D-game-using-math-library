#pragma once
#include "GameObject.h"
#include "TankController.h"

class Ship :
	public GameObject
{
public:
	Ship(const char * textureName);
	~Ship();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

private:
	TankController* _tankController;
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

