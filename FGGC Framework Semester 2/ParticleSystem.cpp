#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(XMFLOAT3 pos)
{
	_pos = pos;
}


ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::Update(float t)
{
	for (int i = 0; i > particles.size(); i++)
	{
		// Erases particle if energy iis 0;
		if (particles.at(i)->GetParticleModel()->getEnergy() == 0)
		{
			particles.erase(particles.begin() + i);
		}

		particles.at(i)->GetParticleModel()->setEnergy(particles.at(i)->GetParticleModel()->getEnergy() - 1);
	}
}

void ParticleSystem::Draw()
{

}