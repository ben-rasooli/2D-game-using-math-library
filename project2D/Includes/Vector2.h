#pragma once
struct Vector2
{
	Vector2();
	Vector2(float x, float y);

	float magnitude();
	float magnitudeSqr();
	float distance(Vector2 other);
	void normalise();
	Vector2 normalised();
	float dot(Vector2& other);
	Vector2 right();
	Vector2 left();
	static Vector2 lerp(Vector2 startPoint, Vector2 endPoint, float percent);
	static Vector2 zero();

	//operstors
	Vector2 operator+(Vector2& other);
	Vector2 operator-(Vector2& other);
	Vector2 operator*(float multiplier);
	Vector2 operator/(float divider);
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	float& operator[](int index);
	operator float*();

	float x, y;
};

Vector2 operator*(float multiplier, Vector2 vector2);
