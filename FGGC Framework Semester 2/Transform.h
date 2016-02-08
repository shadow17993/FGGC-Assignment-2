#include <directxmath.h>

using namespace DirectX;

#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	void SetParent(Transform * parent) { _parent = parent; }

	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }


	void SetPosition(XMFLOAT3 position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	XMFLOAT3 GetPosition() const { return _position; }


	void SetScale(XMFLOAT3 scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	XMFLOAT3 GetScale() const { return _scale; }


	void SetRotation(XMFLOAT3 rotation) { _rotation = rotation; }
	void SetRotation(float x, float y, float z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }

	XMFLOAT3 GetRotation() const { return _rotation; }


	void Update(float t);

private:
	XMFLOAT3 _position;
	XMFLOAT3 _rotation;
	XMFLOAT3 _scale;
	

	XMFLOAT4X4 _world;

	Transform * _parent;
};

