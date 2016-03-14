#pragma once

#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>

using namespace DirectX;

class IPhysicalParticle
{
public:
	IPhysicalParticle(XMFLOAT3 position, XMFLOAT3 velocity, XMFLOAT3 force);
	~IPhysicalParticle();

	XMFLOAT3 getPosition();
	XMFLOAT3 getVelocity();
	XMFLOAT3 getForce();

	void Update(float t);
	void ApplyForce(XMFLOAT3 &force);

private:
	XMFLOAT3 _position;
	XMFLOAT3 _velocity;
	XMFLOAT3 _force;
	float _energy;
};

