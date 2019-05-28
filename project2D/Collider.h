#pragma once
#include "Vector2.h"

class Collider
{
public:
	Collider(Vector2 extend);
	~Collider();

	void SetPosition(Vector2 position);
	bool IsCollidingWith(Collider other);

	Vector2 GetMin();
	Vector2 GetMax();
	Vector2 GetExtend() { return _extend; }

private:
	Vector2 _position;
	Vector2 _extend;

};

