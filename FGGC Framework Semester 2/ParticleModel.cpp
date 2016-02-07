#include "ParticleModel.h"


ParticleModel::ParticleModel(Transform* transform) : _transform(transform)
{
	
	isConstVel = true;
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


void ParticleModel::moveConstAccel(float t)
{

	_transform->SetPosition(_transform->GetPosition().x + _transform->getVel().x * t + 0.5f * _transform->getAccel().x  * t * t,
							_transform->GetPosition().y + _transform->getVel().y * t + 0.5f * _transform->getAccel().y * t * t,
							_transform->GetPosition().z + _transform->getVel().z * t + 0.5f * _transform->getAccel().z * t * t);

	_transform->setVel(_transform->getVel().x + _transform->getAccel().x * t,
					   _transform->getVel().y + _transform->getAccel().y * t,
					   _transform->getVel().z + _transform->getAccel().z * t);
}

void ParticleModel::moveConstVel(float t)
{
	_transform->SetPosition(_transform->GetPosition().x + _transform->getVel().x * t,
							_transform->GetPosition().y + _transform->getVel().y * t,
							_transform->GetPosition().z + _transform->getVel().z * t);
}

void ParticleModel::Update(float t)
{
	if (GetAsyncKeyState('S'))
	{
		isConstVel = !isConstVel;
	}

	if (isConstVel)
	{
		moveConstVel(t);
	}
	else
	{
		moveConstAccel(t);
	}
}