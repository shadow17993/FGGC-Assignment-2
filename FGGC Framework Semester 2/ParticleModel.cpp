#include "ParticleModel.h"


ParticleModel::ParticleModel(Transform* transform, bool useConstVel, XMFLOAT3 initVel, XMFLOAT3 initAccel) : _transform(transform)
{
	_isConstVel = useConstVel;
	_isSpinConstVel = true;

	/*_velocity = { 0.0f, 0.0f, 0.001f };
	_acceleration = { 0.0f, 0.0f, 0.001f };*/

	_velocity = initVel;
	_acceleration = initAccel;
	_spinVelocity = { 0.0f, 0.001f, 0.0f };
	_spinAccel = { 0.0f, 0.001f, 0.0f };
	_force = { 0.0f, 0.0f, 0.0f };
	_mass = 1.0f;
	_gravity = -9.8f;
	_initPos = _transform->GetPosition();
}


ParticleModel::~ParticleModel()
{
}


void ParticleModel::Move(float x, float y, float z)
{
	XMFLOAT3 position = _transform->GetPosition();

	position.x += x;
	position.y += y;
	position.z += z;

	_transform->SetPosition(position);
}


//					Movement				//
void ParticleModel::moveConstVel(float t)
{
	_transform->SetPosition(_transform->GetPosition().x + getVel().x * t,
							_transform->GetPosition().y + getVel().y * t,
							_transform->GetPosition().z + getVel().z * t);
}

void ParticleModel::moveConstAccel(float t)
{

	_transform->SetPosition(_transform->GetPosition().x + getVel().x * t + 0.5f * getAccel().x * t * t,
							_transform->GetPosition().y + getVel().y * t + 0.5f * getAccel().y * t * t,
							_transform->GetPosition().z + getVel().z * t + 0.5f * getAccel().z * t * t);

	setVel(getVel().x + getAccel().x * t,
		   getVel().y + getAccel().y * t,
		   getVel().z + getAccel().z * t);
}


//					Rotation				 //
void ParticleModel::spinConstVel(float t)
{
	_transform->SetRotation(_transform->GetRotation().x + getSpinVel().x * t,
							_transform->GetRotation().y + getSpinVel().y * t,
							_transform->GetRotation().z + getSpinVel().z * t);
}

void ParticleModel::spinConstAccel(float t)
{
	_transform->SetRotation(_transform->GetRotation().x + getSpinVel().x * t + 0.5f * getSpinAccel().x * t * t,
							_transform->GetRotation().y + getSpinVel().y * t + 0.5f * getSpinAccel().y * t * t,
							_transform->GetRotation().z + getSpinVel().z * t + 0.5f * getSpinAccel().z * t * t);

	setSpinVel(getSpinVel().x + getSpinAccel().x * t,
			   getSpinVel().y + getSpinAccel().y * t,
			   getSpinVel().z + getSpinAccel().z * t);
}


void ParticleModel::UpdateNetForce()
{
	_netForce.x += _force.x;
	_netForce.y += _force.y;
	_netForce.z += _force.z;
}


void ParticleModel::UpdateAccel()
{
	_acceleration.x = _netForce.x / _mass;
	_acceleration.y = _netForce.y / _mass;
	_acceleration.z = _netForce.z / _mass;
}

void ParticleModel::UpdateVertThrust()
{

}

void ParticleModel::Update(float t)
{
	if (GetAsyncKeyState('S'))
	{
		_isConstVel = !_isConstVel;
	}

	if (GetAsyncKeyState('R'))
	{
		_isSpinConstVel = !_isSpinConstVel;
	}

	UpdateNetForce();

	UpdateAccel();

	if (_isConstVel)
	{
		moveConstVel(t);
	}
	else
	{
		moveConstAccel(t);
	}

	if (_isSpinConstVel)
	{
		spinConstVel(t);
	}
	else
	{
		spinConstAccel(t);
	}
}