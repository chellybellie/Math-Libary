#pragma once
#include "Ridgedbody.h"

class PlanetaryMotor
{
public:
	float m_rotationSpeed;

	void update(Rigidbody &PlanetRbody);
};