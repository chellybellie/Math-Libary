#include "gamestate.h"
#include "ObjectCollision.h"
#include "Asteroid.h"

void GameState::play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;

	asteroid[0].transform.m_parent = &player.transform;	// bottom right
	asteroid[0].transform.m_position = (vec2{ 10,-2 });	

	asteroid[1].transform.m_parent = &player.transform;// bottom left
	asteroid[1].transform.m_position = (vec2{ -10,-2 });

	asteroid[2].transform.m_parent = &player.transform; // mid left
	asteroid[2].transform.m_position = (vec2{ -5,2 });

	asteroid[3].transform.m_parent = &player.transform; // mid right
	asteroid[3].transform.m_position = (vec2{ 5, 2});
}


void GameState::update(float deltatime)
{
	player.update(deltatime, *this);
	Camera.update(deltatime, *this);

	for (int i = 0; i < 4; ++i)
		asteroid[i].update(deltatime, *this);

	for (int i = 0; i < 4; ++i)
		PlayerAstroidCollision(player, asteroid[i]);

	for (int i = 0; i < 4 - 1; ++i)
		for (int j = i + 1; j < 4; ++j)
			AsteroidCollision(asteroid[i], asteroid[j]);
	
	for (int i = 0; i < player.BULLET_COUNT; ++i)
		for (int j = 0; j < 4; ++j)
			BulletAsteroidCollision(player.bullets[i], asteroid[j]);
}

void GameState::draw()
{
	mat3 cam = Camera.getcameraMatrix();
	player.draw(cam);
	//player.drawHealth();

	for (int i = 0; i < 4; ++i)
		asteroid[i].draw(cam);

}
