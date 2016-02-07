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


	void setAccel(XMFLOAT3 acceleration) { _acceleration = acceleration; }
	void setAccel(float x, float y, float z) { _acceleration = { x, y, z }; }

	XMFLOAT3 getAccel() { return _acceleration; }


	void setVel(XMFLOAT3 velocity) { _velocity = velocity; }
	void setVel(float x, float y, float z) { _velocity = { x, y, z }; }

	XMFLOAT3 getVel() { return _velocity; }


	void setSpinAccel(XMFLOAT3 acceleration) { _spinAccel = acceleration; }
	void setSpinAccel(float x, float y, float z) { _spinAccel = { x, y, z }; }

	XMFLOAT3 getSpinAccel() { return _spinAccel; }


	void setSpinVel(XMFLOAT3 velocity) { _spinVelocity = velocity; }
	void setSpinVel(float x, float y, float z) { _spinVelocity = { x, y, z }; }

	XMFLOAT3 getSpinVel() { return _spinVelocity; }


	void Update(float t);

private:
	XMFLOAT3 _position;
	XMFLOAT3 _rotation;
	XMFLOAT3 _scale;
	XMFLOAT3 _velocity;
	XMFLOAT3 _acceleration;
	XMFLOAT3 _spinVelocity;
	XMFLOAT3 _spinAccel;

	XMFLOAT4X4 _world;

	Transform * _parent;
};

