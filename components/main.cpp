#include "sfwdraw.h"
#include "vec-2.h"
#include "transform.h"
#include "flops.h"
#include "Ridgedbody.h"
#include "Spaceship.h"
#include "Spaceshipcontroller.h"
#include "planetmotor.h"
#include "PlanetRenderer.h"
#include "SpaceshipRenderer.h"
#include <cstdio>

void main()
{
	float W = 1200, H = 1200;
	sfw::initContext(W, H);
	float steps = 100;
	vec2 start = { 200, 300 },
		 end   = { 900, 800 },
		 mid   = { 0, 1100  };

		Transform playerTransform(200, 200);
		
		playerTransform.m_scale = { 20, 20 };
		Rigidbody playerRigidbody;
		SpaceshipController Playerctrl;
		Spaceshiplocomotion Playerloco;
		SpaceshipRenderer playerRender;
		


		//sun
		Transform sunTransform;
		sunTransform.m_position = vec2{ W / 2, H / 2 };
		Rigidbody sunRbody;
		PlanetaryMotor sunMotor;
		sunMotor.m_rotationSpeed = 3;
		PlanetaryRenderer sunRenderer(YELLOW, 100);

		//Planet
		Transform plan1;
		plan1.m_position = vec2{ 150, 0 };
		plan1.m_parent = &sunTransform;
		Rigidbody plan1RB;
		PlanetaryMotor plan1motor;
		plan1motor.m_rotationSpeed = 2;
		PlanetaryRenderer plan1renderer(GREEN, 20);

		//moon
		Transform moon1;
		moon1.m_position = vec2{ 50,0 };
		moon1.m_parent = &plan1;
		Rigidbody moon1RB;
		PlanetaryMotor moon1motor;
		moon1motor.m_rotationSpeed = 2;
		PlanetaryRenderer moon1renderer(WHITE, 4);
		

		Transform cameraTransform;

		while (sfw::stepContext())
		{
			float deltaTime = sfw::getDeltaTime();

		// apply rigidbody forces
			Playerctrl.update(Playerloco);
			Playerloco.update(playerTransform, playerRigidbody);
			playerRigidbody.integrate(playerTransform, deltaTime);


			// update logic
			sunMotor.update(sunRbody);
			plan1motor.update(plan1RB);
			moon1motor.update(moon1RB);
			
			
			moon1RB.integrate(moon1, deltaTime);
			plan1RB.integrate(plan1, deltaTime);
			sunRbody.integrate(sunTransform, deltaTime);

			cameraTransform.m_position
									= lerp(cameraTransform.m_position,
									(playerTransform.getGlobalPosition() + sunTransform.getGlobalPosition())/2,
									sfw::getDeltaTime() * 10);

			

			mat3 proj = translate(W/2, H/2) * scale(1.f, 1.f);
			mat3 view = inverse(cameraTransform.getGlobalTransform());

			mat3 camera = proj * view;

			
			playerTransform.debugDraw(camera);
			sunTransform.debugDraw(camera);
			plan1.debugDraw(camera);
			moon1.debugDraw(camera);
			cameraTransform.debugDraw(camera);

			playerRigidbody.debugDraw(camera, playerTransform);

			sunRenderer.draw(camera, sunTransform);
			plan1renderer.draw(camera, plan1);
			moon1renderer.draw(camera, moon1);

			playerRender.draw(camera, playerTransform);
		}
		sfw::termContext();
	
}

