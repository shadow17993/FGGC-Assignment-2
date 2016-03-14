#pragma once

#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>

using namespace DirectX;

class IDrawableParticle
{
public:
	IDrawableParticle();
	~IDrawableParticle();

	void Draw();
	void Update();
};

