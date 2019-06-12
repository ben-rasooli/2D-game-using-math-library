#include "Tank.h"
#include "Input.h"

Tank::Tank(const char * textureName) : GameObject(textureName)
{
	_collider = new BoxCollider(Vector2(38, 37));
	CollisionManager::I()->AddGameObject(this, CollisionLayer::TANK);
}

Tank::~Tank() {}

void Tank::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	// should override the GameObject._collider.SetPosition(), because my _localPosition stays zero
	_collider->SetPosition(_globalTransform.getPosition());
}

void Tank::Draw(aie::Renderer2D * renderer)
{
	GameObject::Draw(renderer);
}
