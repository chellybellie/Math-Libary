#pragma once
#include "transform.h"
#include "collider.h"
#include "Ridgedbody.h"
#include "Asteroid.h"
#include "spaceship Child.h"
//#include "gamestate.h"

class Ultimate {

public:
	Transform	transform;
	Collider	collider;
	Rigidbody	rigidbody;
	Asteroid	asteroid;
	ShipChild	shipchild;

	Ultimate();

	float timer = 0;
	bool isAlive;

	void update(float deltatime, class GameState &gs);
	void draw(const mat3 &camera);

	void Ultimate::drawEffect0(Transform & planeTrans, const mat3 & T);
	void Ultimate::drawEffect1(Transform & planeTrans, const mat3 & T);
	void Ultimate::drawEffect2(Transform & planeTrans, const mat3 & T);
};

