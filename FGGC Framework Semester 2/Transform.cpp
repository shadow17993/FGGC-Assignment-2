#include "Transform.h"


Transform::Transform()
{
	_parent = nullptr;
	_position = XMFLOAT3();
	_rotation = XMFLOAT3();
	_scale = XMFLOAT3(1.0f, 1.0f, 1.0f);
	_velocity = { 0.0f, 0.0f, 0.001f };
	_acceleration = { 0.0f, 0.0f, 0.001f };
	_spinVelocity = { 0.0f, 0.001f, 0.0f };
	_spinAccel = { 0.0f, 0.001f, 0.0f };
}


Transform::~Transform()
{
}


void Transform::Update(float t)
{
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	XMMATRIX rotation = XMMatrixRotationX(_rotation.x) * XMMatrixRotationY(_rotation.y) * XMMatrixRotationZ(_rotation.z);
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}
}