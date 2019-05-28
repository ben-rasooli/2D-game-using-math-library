#pragma once
#include "../DataStructuresLib/List.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Matrix3.h"
#include "Collider.h"

class GameObject
{
public:
	GameObject();
	GameObject(const char* textureName);
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* renderer);

	void UpdateGlobalTransform();

	void SetPosition(Vector2 pos);
	void SetPosition(float x, float y);
	void SetRotation(float radians);
	void SetScale(Vector2 scale);

	void Translate(Vector2 translation);
	void Rotate(float radians);

	void SetParent(GameObject* parent);
	void AddChild(GameObject* parent);

	Vector2 GetPosition();
	float GetRotation();
	Vector2 GetScale();
	GameObject* GetParent();
	Collider* GetCollider() { return _collider; }

protected:
	GameObject* _parent;
	List<GameObject*> _childList;

	Matrix3 _localTransform;
	Matrix3 _globalTransform;

	aie::Texture* _texture;

	Collider* _collider;

};

