#include "gamestate.h"
#include "ObjectCollision.h"
#include "Asteroid.h"

void GameState::play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;


	asteroid[0].transform.m_position = vec2{ 0,0 };
	asteroid[0].rigidbody.addImpulde(vec2{ 100,100 });
	asteroid[0].rigidbody.addTorque(24);

	asteroid[1].transform.m_position = vec2{ 400,400 };
	asteroid[1].rigidbody.addImpulde(vec2{ -100,-100 });
	asteroid[1].rigidbody.addTorque(-24);
}

void GameState::update(float deltatime)
{
	player.update(deltatime, *this);
	Camera.update(deltatime, *this);

	for (int i = 0; i < 1; ++i)
		asteroid[i].update(deltatime, *this);

	for (int i = 0; i < 1; ++i)
		PlayerAstroidCollision(player, asteroid[i]);

	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AsteroidCollision(asteroid[i], asteroid[j]);
}

void GameState::draw()
{
	mat3 cam = Camera.getcameraMatrix();
	player.draw(cam);
	player.drawHealth();
	for (int i = 0; i < 2; ++i)
		asteroid[i].draw(cam);
}
