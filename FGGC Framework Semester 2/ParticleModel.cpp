#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, bool useConstVel, XMFLOAT3 initVel, XMFLOAT3 initAccel) : _transform(transform)
{
	_isConstVel = useConstVel;
	_isSpinConstVel = true;

	_velocity = initVel;
	_acceleration = initAccel;
	_spinVelocity = { 0.0f, 0.001f, 0.0f };
	_spinAccel = { 0.0f, 0.001f, 0.0f };

	_thrust = { 0.0f, 0.0f, 0.0f };
	_brake = { 0.0f, 0.0f, 0.0f };
	_friction = { 0.0f, 0.0f, 0.0f };
	_netForce = { 0.0f, 0.0f, 0.0f };

	_mass = 1.0f;
	_gravity = -9.8f;
	_weight = _mass * _gravity;
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
	_netForce.x = _thrust.x + _brake.x + _friction.x;
	_netForce.y = _thrust.y + _brake.y + _friction.x;
	_netForce.z = _thrust.z + _brake.z + _friction.z;
}


void ParticleModel::UpdateAccel()
{
	_acceleration.x = _netForce.x / _mass;
	_acceleration.y = _netForce.y / _mass;
	_acceleration.z = _netForce.z / _mass;
}

void ParticleModel::UpdateVertThrust()
{

	// If so: apply force

	_transform->SetPosition(_transform->GetPosition().x,
							_transform->GetPosition().y + _netForce.y,
							_transform->GetPosition().z);
}

void ParticleModel::slidingForce(float theta, float frCoef)
{
	float forceMag = _mass * _gravity * (sin(theta) - frCoef * cos(theta));

	_sForce.x = forceMag * cos(theta);
	_sForce.y = forceMag * sin(theta);
}

void ParticleModel::slidingMotion(float t)
{
	slidingForce(0.0f, 0.5f);

	updateState(t);
	moveConstVel(t);
}

void ParticleModel::dragForce(XMFLOAT3 vel, float dragFactor)
{
	if (_laminar)
	{
		dragLamFlow(vel, dragFactor);
	}
	else
	{
		dragTurbFlow(vel, dragFactor);
	}
}

void ParticleModel::dragLamFlow(XMFLOAT3 vel, float dragFactor)
{
	_drag.x = -dragFactor * vel.x;
	_drag.y = -dragFactor * vel.y;
	_drag.z = -dragFactor * vel.z;
}

void ParticleModel::dragTurbFlow(XMFLOAT3 vel, float dragFactor)
{
	XMFLOAT3 velMag;
	XMStoreFloat3(&velMag, XMVector3Length(XMLoadFloat3(&vel)));


	XMFLOAT3 unitVel;
	XMStoreFloat3(&unitVel, XMVector3Normalize(XMLoadFloat3(&vel)));

	float dragMag = dragFactor * velMag.x * velMag.x;

	_drag.x = dragMag * unitVel.x;
	_drag.y = dragMag * unitVel.y;
	_drag.z = dragMag * unitVel.z;
}


void ParticleModel::updateState(float t)
{
	UpdateNetForce();
	UpdateAccel();
	moveConstVel(t);
}

void ParticleModel::Update(float t)
{
	/*if (GetAsyncKeyState('S'))
	{
		_isConstVel = !_isConstVel;
	}

	if (GetAsyncKeyState('R'))
	{
		_isSpinConstVel = !_isSpinConstVel;
	}*/

	if (GetAsyncKeyState('A'))
	{
		_thrust.y = 0.01f;
	}
	else if (_thrust.y >= _initPos.y)
	{
		_thrust.y -= 0.02f;
	}

	UpdateVertThrust();
	slidingMotion(t);

	/*if (_isConstVel)
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
	}*/
}