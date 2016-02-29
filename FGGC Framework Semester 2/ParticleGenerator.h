#include "Transform.h"
#include <windows.h>

using namespace std;
using namespace DirectX;

#pragma once
class Particle
{
public:
	Particle();
	~Particle();

	IPhysicalParticle* particlePhysics;
	IDrawableParticle* drawableParticle;
	void Update(float t);
	void Draw();
};




class IPhysicalParticle
{
public:
	float getMass();
	XMFLOAT3 getPosition();
	XMFLOAT3 getVelocity();
	XMFLOAT3 getForce();

	void Update(float t);
	void ApplyForce(XMFLOAT3 &force);
};




class IDrawableParticle
{
public:
	void Draw();
	void Update(float t);
};




class ParticleSystem
{
	int numParticles;
	Particle* P;

public:
	void Update(float t);
	void Draw();
};