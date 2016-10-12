#include "sfwdraw.h"
#include "vec-2.h"
#include "transform.h"
#include "flops.h"
#include "Ridgedbody.h"
#include "Spaceship.h"
#include "Spaceshipcontroller.h"

using namespace sfw;
void main()
{
	float W = 1200, H = 1200;
	sfw::initContext(W, H);

		SpaceshipController Playerctrl;
		Spaceshiplocomotion Playerloco;
		Transform playerTransform(200, 200);
		playerTransform.m_scale = { 5,5 };
		Rigidbody playerRigidbody;

		while (sfw::stepContext())
		{
			float deltaTime = sfw::getDeltaTime();

			Playerctrl.update(Playerloco);
			Playerloco.update(playerTransform, playerRigidbody, deltaTime);
			playerRigidbody.integrate(playerTransform, deltaTime);
	
			if (playerTransform.m_position.x < 0)	playerTransform.m_position.x = W;
			else if (playerTransform.m_position.x > W)	playerTransform.m_position.x = 0.f;
			if (playerTransform.m_position.y < 0)	playerTransform.m_position.y = H;
			else if (playerTransform.m_position.y> H)	playerTransform.m_position.y = 0.0F;

			playerRigidbody.debugDraw(playerTransform);
			playerTransform.debugDraw();
		}
		sfw::termContext();
	
}

