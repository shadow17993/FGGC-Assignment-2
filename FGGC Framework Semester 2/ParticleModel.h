#include "Transform.h"
#include <windows.h>

using namespace std;
using namespace DirectX;

#pragma once

class ParticleModel
{
public:
	ParticleModel(Transform* transform, bool useConstVel, XMFLOAT3 initVel, XMFLOAT3 initAccel);
	~ParticleModel();

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


	void setForce(XMFLOAT3 force) { _force = force; }
	void setForce(float x, float y, float z) { _force = { x, y, z }; }
	XMFLOAT3 getForce() { return _force; }


	void setMass(float mass) { _mass = mass; }
	float getMass() { return _mass; }

	void setWeight(float weight) { _weight = weight; }
	float getWeight() { return _weight; }

	void setUpforce(float upforce){ _upforce = upforce; }
	float getUpforce() {
		if (_initPos.y >= _transform->GetPosition().y)
		{
			_upforce = 0;
			return _upforce;
		}
		else
		{
			return _upforce;
		}
	}
	

	bool setIsConstVel(bool isConstVel) { _isConstVel = isConstVel; }
	bool setIsSpinConstVel(bool isSpinConstVel) { _isSpinConstVel = isSpinConstVel; }

	void Move(float x, float y, float z);
	void moveConstVel(float t);
	void moveConstAccel(float t);

	void spinConstVel(float t);
	void spinConstAccel(float t);

	void UpdateNetForce();

	void UpdateAccel();

	void UpdateVertThrust();

	void Update(float t);


private:
	Transform* _transform;
	XMFLOAT3 _initPos;
	XMFLOAT3 _velocity;
	XMFLOAT3 _acceleration;
	XMFLOAT3 _spinVelocity;
	XMFLOAT3 _spinAccel;
	XMFLOAT3 _force;
	XMFLOAT3 _netForce;
	float _mass;
	float _gravity;
	float _weight;
	float _upforce;
	

	bool _isConstVel;
	bool _isSpinConstVel;
};

