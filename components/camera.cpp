#include "camera.h"
#include "gamestate.h"

camera::camera()
{
	projection = translate(600, 600) * scale(.5f, .5f);
}

mat3 camera::getcameraMatrix() const
{
	return projection * inverse(transform.getGlobalTransform());
}

void camera::update(float deltatime, GameState & gs)
{
	transform.m_position = gs.player.transform.getGlobalPosition();
}
