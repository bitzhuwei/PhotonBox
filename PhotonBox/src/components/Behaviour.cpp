#include "PhotonBox/components/Behaviour.h"

#include "PhotonBox/core/systems/Logic.h"

Behaviour::Behaviour()
{
	Logic::addToUpdateList(this);
}

void Behaviour::destroy()
{
	OnDestroy();
	Logic::removeFromList(this);
}

void Behaviour::Start() {}
void Behaviour::Update() {}
void Behaviour::FixedUpdate() {}
void Behaviour::LateUpdate() {}
void Behaviour::OnDestroy() {}
