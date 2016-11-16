#pragma once
#include "transform.h"

class camera
{
public:
	mat3		projection;
	Transform	transform;

	camera();
	mat3 getcameraMatrix() const;
	void update(float deltatime, class GameState &gs);

};