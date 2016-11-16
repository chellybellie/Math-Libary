#include "Spaceshipcontroller.h"
#include "sfwdraw.h"
#include "Spaceship.h"

SpaceshipController::SpaceshipController(unsigned a_CTR_LEFT, unsigned a_CTR_RIGHT, unsigned a_CTR_UP, unsigned a_CTR_DOWN, unsigned a_CTR_break)
{
	CTR_LEFT = a_CTR_LEFT;
	CTR_RIGHT = a_CTR_RIGHT;
	CTR_UP = a_CTR_UP;
	CTR_DOWN = a_CTR_DOWN;
	CTR_break = a_CTR_break;

}

void SpaceshipController::update(Spaceshiplocomotion & loco)
{
	float hInput = 0.0f;
	hInput += sfw::getKey(CTR_LEFT);
	hInput -= sfw::getKey(CTR_RIGHT);

	float vInput = 0.0f;

	vInput -= sfw::getKey(CTR_DOWN);
	vInput += sfw::getKey(CTR_UP);

	float bInput = sfw::getKey(CTR_break);

	loco.doStop(bInput);
	loco.doThrust(vInput);
	loco.doTurn(hInput);
	

}