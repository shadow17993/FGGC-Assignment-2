#pragma once

#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>
#include "IDrawableParticle.h"
#include "IPhysicalParticle.h"

using namespace DirectX;

class Particle
{
public:
	Particle();
	~Particle();

	IPhysicalParticle* particlePhysics;
	IDrawableParticle* drawablePhysics;

	

	void Update(float t);
	void Draw();

private:


};

