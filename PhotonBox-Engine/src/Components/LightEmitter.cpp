#include "LightEmitter.h"
#include "../Core/Systems/Lighting.h"

LightEmitter::LightEmitter() {
	Vector3f color = Vector3f::ZERO;
	float intensity = 1;
	Lighting::addLight(this);
}