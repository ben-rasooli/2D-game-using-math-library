#include "Collider.h"

Collider::Collider(Vector2 extend)
{
	_extend = extend;
}

Collider::~Collider() {}

void Collider::SetPosition(Vector2 position)
{
	_position = position;
}

bool Collider::IsCollidingWith(Collider other)
{
	Vector2 myMin = GetMin();
	Vector2 myMax = GetMax();
	Vector2 otherMin = other.GetMin();
	Vector2 otherMax = other.GetMax();

	//any gap
	if (myMax.x < otherMin.x || otherMax.x < myMin.x ||
		myMax.y < otherMin.y || otherMax.y < myMin.y)
		return false;

	return true;
}

Vector2 Collider::GetMin()
{
	return _position - _extend;
}

Vector2 Collider::GetMax()
{
	return _position + _extend;
}
