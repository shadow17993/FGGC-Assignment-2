#include "GameObject.h"

GameObject::GameObject(string type, Transform* transform, ParticleModel* particleModel, Appearance* appearance) : _type(type), _transform(transform), _particleModel(particleModel), _appearance(appearance)
{
	
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	_transform->Update(t);
	_particleModel->Update(t);
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_appearance->Draw(pImmediateContext);
}
