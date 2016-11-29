#pragma once
#include "transform.h"
#include "Collider.h"
#include "Ridgedbody.h"
#include "Spaceship.h"
#include "Bullets.h"
#include "camera.h"

class ShipChild
{

public:
	Transform  transform;
	Collider   collider;
	Rigidbody  rigidbody;
	

	ShipChild();

	float timer;
	float offset;
	bool active;


	void update(float deltatime, class GameState &gs);
	void draw(const mat3 &camera);
	
	void activate();

	void drawEffect0(Transform & planeTrans, const mat3 & T);
	void drawEffect1(Transform & planeTrans, const mat3 & T);
	void drawEffect2(Transform & planeTrans, const mat3 & T);
};