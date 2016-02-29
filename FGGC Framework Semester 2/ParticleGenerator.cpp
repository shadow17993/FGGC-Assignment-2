#include "ParticleGenerator.h"


Particle::Particle()
{
}


Particle::~Particle()
{
}

void Particle::Update(float t)
{

}

void Particle::Draw()
{

}


//		IPHYSICAL PARTICLE
void IPhysicalParticle::Update(float t)
{

}

void IPhysicalParticle::ApplyForce(XMFLOAT3 &force)
{

}


//		IDRAWABLE PARTICLE
void IDrawableParticle::Draw()
{

}

void IDrawableParticle::Update(float t)
{

}


//		PARTICLE SYSTEM
void ParticleSystem::Update(float t)
{

}

void ParticleSystem::Draw()
{

}