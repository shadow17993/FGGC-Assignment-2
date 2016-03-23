#include "Particle.h"


Particle::Particle(string type, Transform* transform, ParticleModel* particleModel, Appearance* appearance) : _transform(transform), _particlePhysics(particleModel), _drawablePhysics(appearance)
{
	_energy = rand() % 300;
}


Particle::~Particle()
{
}

void Particle::Update(float t)
{
	_particlePhysics->Update(t);

	// Reduces energy with each frame
	_energy--;
}

void Particle::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_drawablePhysics->Draw(pImmediateContext);
}