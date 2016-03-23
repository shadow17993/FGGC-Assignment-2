#pragma once

#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>
#include "Particle.h"
#include <vector>
#include "GameObject.h"

using namespace DirectX;
using namespace std;

class ParticleSystem
{
public:
	ParticleSystem(Transform* transform);
	~ParticleSystem();

	Transform* getTransform(){ return _transform; }


	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);

private:

	vector<Particle*> particles;
	XMFLOAT3 _pos;

	Transform* _transform;
};

