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
#include "Collider.h"

void main()
{
	float W = 1200, H = 1200;
	sfw::initContext(W, H);
	float steps = 100;
	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100 };

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
	sunMotor.m_rotationSpeed = 1;
	PlanetaryRenderer sunRenderer(YELLOW, 100);

	//Planet
	Transform plan1;
	plan1.m_position = vec2{ 150, 10 };
	plan1.m_parent = &sunTransform;
	Rigidbody plan1RB;
	PlanetaryMotor plan1motor;
	plan1motor.m_rotationSpeed = 1;
	PlanetaryRenderer plan1renderer(GREEN, 20);

	//planet2
	Transform plan2;
	plan2.m_position = vec2{ 250, 0 };
	plan2.m_parent = &sunTransform;
	Rigidbody plan2RB;
	PlanetaryMotor plan2motor;
	plan2motor.m_rotationSpeed = 2;
	PlanetaryRenderer plan2renderer(CYAN, 40);

	//planet3
	Transform plan3;
	plan3.m_position = vec2{ 350, 0 };
	plan3.m_parent = &sunTransform;
	Rigidbody plan3RB;
	PlanetaryMotor plan3motor;
	plan3motor.m_rotationSpeed = 2;
	PlanetaryRenderer plan3renderer(RED, 10);

	//moon
	Transform moon1;
	moon1.m_position = vec2{ 40,0 };
	moon1.m_parent = &plan1;
	Rigidbody moon1RB;
	PlanetaryMotor moon1motor;
	moon1motor.m_rotationSpeed = 2;
	PlanetaryRenderer moon1renderer(WHITE, 4);
	
	//moon 4 planet3
	Transform moon2;
	moon2.m_position = vec2{ 40,0 };
	moon2.m_parent = &plan3;
	Rigidbody moon2RB;
	PlanetaryMotor moon2motor;
	moon2motor.m_rotationSpeed = 2;
	PlanetaryRenderer moon2renderer(BLACK, 4);


	Transform cameraTransform;                       

	///Collider//////
	vec2 hullVrts[] = { { 0,8.5 }, {-4.5,-1 },{-2,-6},{-2,-1},{0,-.5},{2,-1}, {2,-6},{ 4.5,-1} };
	Collider PlayerColider(hullVrts, 8);

	Transform occluderTransform(0, 0);
	occluderTransform.m_scale = vec2{ 8,8 };
	Collider occluderCollider(hullVrts, 8);
	Rigidbody occluderRidgidbody;

		while (sfw::stepContext())
		{
			float deltaTime = sfw::getDeltaTime();

		// apply rigidbody forces
			Playerctrl.update(Playerloco);
			Playerloco.update(playerTransform, playerRigidbody);
			playerRigidbody.integrate(playerTransform, deltaTime);

		
			StaticResolution(playerTransform, playerRigidbody, PlayerColider,
			                  occluderTransform, occluderCollider);
		
			DynamicResolution(playerTransform, playerRigidbody, PlayerColider,
				occluderTransform, occluderRidgidbody, occluderCollider);

			// update logic
			sunMotor.update(sunRbody);
			plan1motor.update(plan1RB);
			plan2motor.update(plan2RB);
			plan3motor.update(plan3RB);
			moon1motor.update(moon1RB);
			moon2motor.update(moon1RB);
			
			
			moon1RB.integrate(moon1, deltaTime);
			moon2RB.integrate(moon1, deltaTime);
			plan1RB.integrate(plan1, deltaTime);
			plan2RB.integrate(plan2, deltaTime);
			plan3RB.integrate(plan3, deltaTime);
			sunRbody.integrate(sunTransform, deltaTime);

			cameraTransform.m_position
									= lerp(cameraTransform.m_position,
									(playerTransform.getGlobalPosition()),/* + sunTransform.getGlobalPosition())/2,*/
									sfw::getDeltaTime() * 10);

			

			mat3 proj = translate(W/2, H/2) * scale(1.f, 1.f);
			mat3 view = inverse(cameraTransform.getGlobalTransform());

			mat3 camera = proj * view;

			
			playerTransform.debugDraw(camera);

			///shows Collision shape w/ box/////
			//PlayerColider.DebugDraw(camera,playerTransform);
			occluderCollider.DebugDraw(camera, occluderTransform);
			sunTransform.debugDraw(camera);
			plan1.debugDraw(camera);
			plan2.debugDraw(camera);
			plan3.debugDraw(camera);
			moon1.debugDraw(camera);
			moon2.debugDraw(camera);
			cameraTransform.debugDraw(camera);

			playerRigidbody.debugDraw(camera, playerTransform);

			sunRenderer.draw(camera, sunTransform);
			plan1renderer.draw(camera, plan1);
			plan2renderer.draw(camera, plan2);
			plan3renderer.draw(camera, plan3);
			moon1renderer.draw(camera, moon1);
			moon2renderer.draw(camera, moon1);


			playerRender.draw(camera, playerTransform);
		}
		sfw::termContext();
	
}

