#include "planetmotor.h"

void PlanetaryMotor::update(Rigidbody &PlanetRbody)
{
	PlanetRbody.addTorque(m_rotationSpeed);
}
