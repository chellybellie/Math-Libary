#pragma once

#include "transform.h"
#include "matrix3.h"

class SpaceshipRenderer
{

public:
	unsigned color;
	SpaceshipRenderer();

	void draw(const mat3 &T, const Transform &ship);
};