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
		playerTransform.scale = { 5,5 };
		Rigidbody playerRigidbody;

		while (sfw::stepContext())
		{
			float deltaTime = sfw::getDeltaTime();

			Playerctrl.update(Playerloco);
			playerRigidbody.integrate(playerTransform, deltaTime);
			Playerloco.update(playerRigidbody, deltaTime);
		
		
	
			if (playerTransform.position.x < 0)	playerTransform.position.x = W;
			else if (playerTransform.position.x > W)	playerTransform.position.x = 0.f;
			if (playerTransform.position.y < 0)	playerTransform.position.y = H;
			else if (playerTransform.position.y> H)	playerTransform.position.y = 0.0F;

		playerTransform.debugDraw();
		}
		sfw::termContext();
	
}

