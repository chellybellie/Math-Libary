#include "sfwdraw.h"
#include "vec-2.h"
#include "transform.h"
#include "flops.h"
#include "Ridgedbody.h"
#include "Spaceship.h"
#include "Spaceshipcontroller.h"
#include "planetmotor.h"
#include "PlanetRenderer.h"
#include <cstdio>

using namespace sfw;
void main()
{
	float W = 1200, H = 1200;
	sfw::initContext(W, H);
	

		SpaceshipController Playerctrl;
		Spaceshiplocomotion Playerloco;
		Transform playerTransform(100, 100);
		playerTransform.m_scale = { 5, 5 };
		Rigidbody playerRigidbody;

		//sun
		Transform sunTransform;
		sunTransform.m_position = vec2{ W / 2, H / 2 };
		Rigidbody sunRbody;
		PlanetaryMotor sunMotor;
		sunMotor.m_rotationSpeed = 5;
		PlanetaryRenderer sunRenderer(YELLOW, 100);

		//Planet
		Transform plan1;
		plan1.m_position = vec2{ 150, 0 };
		plan1.m_parent = &sunTransform;
		Rigidbody plan1RB;
		PlanetaryMotor plan1motor;
		plan1motor.m_rotationSpeed = 7;
		PlanetaryRenderer plan1renderer(GREEN, 20);

		//moon
		Transform moon1;
		moon1.m_position = vec2{ 200,0 };
		moon1.m_parent = &plan1;
		Rigidbody moon1RB;
		PlanetaryMotor moon1motor;
		moon1motor.m_rotationSpeed = 7;
		PlanetaryRenderer moon1renderer(WHITE, 4);
		

		Transform cameraTransform;

		while (sfw::stepContext())
		{
			float deltaTime = sfw::getDeltaTime();

		
			Playerctrl.update(Playerloco);
			Playerloco.update(playerTransform, playerRigidbody);
			sunMotor.update(sunRbody);
			plan1motor.update(plan1RB);
			moon1motor.update(moon1RB);
			
			playerRigidbody.integrate(playerTransform, deltaTime);
			moon1RB.integrate(moon1, deltaTime);
			plan1RB.integrate(plan1, deltaTime);
			sunRbody.integrate(sunTransform, deltaTime);

			cameraTransform.m_position
								= lerp(cameraTransform.m_position,
								playerTransform.getGlobalPosition(),
								sfw::getDeltaTime() * 2);

			mat3 proj = translate(W/2, H/2) * scale(1.f, .2f);
			mat3 view = inverse(cameraTransform.getGlobalTransform());

			mat3 camera = proj * view;


			playerTransform.debugDraw(camera);
			sunTransform.debugDraw(camera);
			plan1.debugDraw(camera);
			moon1.debugDraw(camera);
			cameraTransform.debugDraw(camera);

			playerRigidbody.debugDraw(camera, playerTransform);


			//if (playerTransform.m_position.x < 0)	playerTransform.m_position.x = W;
			//else if (playerTransform.m_position.x > W)	playerTransform.m_position.x = 0.f;
			//if (playerTransform.m_position.y < 0)	playerTransform.m_position.y = H;
			//else if (playerTransform.m_position.y> H)	playerTransform.m_position.y = 0.0F;



		}
		sfw::termContext();
	
}

