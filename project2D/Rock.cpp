#include "Rock.h"

Rock::Rock(Vector2 position) : GameObject("rock_large.png")
{
	_localTransform.setPosition(position);

	_collider = new BoxCollider(Vector2(40, 40));
	CollisionManager::I()->AddGameObject(this, CollisionLayer::Obstacle);
}

void Rock::OnCollision(GameObject * other)
{
	Rotate(0.02f);
}
