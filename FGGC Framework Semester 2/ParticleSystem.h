#pragma once

#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>
#include "Particle.h"

using namespace DirectX;

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void Update(float t);
	void Draw();

private:
	int numParticle;
	Particle* p;
};

