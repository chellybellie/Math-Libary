#include "sfwdraw.h"
#include "vec-2.h"
#include "transform.h"
#include "flops.h"
#include "Ridgedbody.h"
#include "Spaceship.h"
#include "Spaceshipcontroller.h"
#include <cstdio>

using namespace sfw;
void main()
{
	float W = 800, H = 600;
	sfw::initContext(W, H);
	

		SpaceshipController Playerctrl;
		Spaceshiplocomotion Playerloco;
		Transform playerTransform(5, 5);
		playerTransform.m_scale = { 5, 5 };
		Rigidbody playerRigidbody;


	Transform ST1(5, 0);
	SpaceshipController ST1ctrl('A', 'D', 'T', 'E', ' ');
	Spaceshiplocomotion ST1loco;

	Transform ST2(10, 0);
	SpaceshipController ST2ctrl('A', 'D', 'T', 'E', ' ');
	Spaceshiplocomotion ST2loco;
	

	Transform ST3(15, 0);
	ST1.m_parent = &playerTransform;
	ST2.m_parent = &ST1;
	ST3.m_parent = &ST2;

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

		playerTransform.debugDraw();
		//playerRigidbody.debugDraw(playerTransform);

		
		ST1loco.update(playerTransform, playerRigidbody, deltaTime);
		ST1ctrl.STupdate(ST1loco, ST1);
		ST1.debugDraw();


		ST2loco.update(playerTransform, playerRigidbody, deltaTime);
		ST2ctrl.STupdate(ST2loco, ST2);
		ST2.debugDraw();
		ST3.debugDraw();
		}
		sfw::termContext();
	
}

