#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(Transform* transform)
{
	_transform = transform;
}


ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::Update(float t)
{
	if (particles.size() != 100)
	{
		Transform* t = new Transform();
		ParticleModel* pm = new ParticleModel(t, true, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f });

		particles.push_back(new Particle(t, pm));
	}

	for (int i = 0; i > particles.size(); i++)
	{
		// Erases particle if energy is 0;
		if (particles.at(i)->getEnergy() == 0)
		{
			particles.erase(particles.begin() + i);
		}
	}
}

void ParticleSystem::Draw(ID3D11DeviceContext * pImmediateContext)
{
	for (int i = 0; i > particles.size(); i++)
	{
		particles.at(i)->Draw(pImmediateContext);
	}
}