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


	for (int i = 0; i > particles.size(); i++)
	{
		// Erases particle if energy iis 0;
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