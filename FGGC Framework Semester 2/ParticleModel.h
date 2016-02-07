#include "Transform.h"
#include <windows.h>

using namespace std;
using namespace DirectX;

#pragma once

class ParticleModel
{
public:
	ParticleModel(Transform* transform);
	~ParticleModel();

	void Move(float x, float y, float z);
	void moveConstVel(float t);
	void moveConstAccel(float t);

	void Update(float t);


private:
	Transform* _transform;

	

	bool isConstVel;
};

