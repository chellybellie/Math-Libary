#pragma once
#include "Spaceship.h"
#include "sfwdraw.h"

class SpaceshipController
{
public:
	unsigned CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_break;

	SpaceshipController(unsigned CTR_LEFT = 'A', unsigned CTR_RIGHT = 'D', unsigned CTR_UP = 'W',
		unsigned CTR_DOWN = 'S', unsigned CTR_break = ' ');

	void update(Spaceshiplocomotion &loco);
	
};