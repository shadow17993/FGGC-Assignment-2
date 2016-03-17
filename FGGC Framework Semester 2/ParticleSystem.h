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
	ParticleSystem(XMFLOAT3 pos);
	~ParticleSystem();

	void Update(float t);
	void Draw();

private:

	vector<GameObject*> particles;
	XMFLOAT3 _pos;

};

