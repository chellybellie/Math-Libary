#include "gamestate.h"
#include "ObjectCollision.h"
#include "Asteroid.h"
#include "Spaceship.h"

void GameState::play()
{
	player.transform.m_position = vec2{ 200,100 };
	player.transform.m_facing = 0;

	asteroid.transform.m_position = (vec2{ 200,1000 });

	shipchild[0].transform.m_parent = &player.transform;	// bottom right
	shipchild[0].transform.m_position = (vec2{ 10,-2 });	
	shipchild[0].offset = 0;

	shipchild[1].transform.m_parent = &player.transform;// bottom left
	shipchild[1].transform.m_position = (vec2{ -10,-2 });
	shipchild[1].offset = 0;

	shipchild[2].transform.m_parent = &player.transform; // mid left
	shipchild[2].transform.m_position = (vec2{ -5,2 });
	shipchild[2].offset = .5;

	shipchild[3].transform.m_parent = &player.transform; // mid right
	shipchild[3].transform.m_position = (vec2{ 5, 2});
	shipchild[3].offset = .5;
}


void GameState::update(float deltatime)
{
	player.update(deltatime, *this);
	Camera.update(deltatime, *this);

	for (int i = 0; i < 4; ++i)
		shipchild[i].update(deltatime, *this);

		PlayerAstroidCollision(player, asteroid);

	for (int i = 0; i < 4 - 1; ++i)
		for (int j = i + 1; j < 4; ++j)
			ShipChildCollision(asteroid, shipchild[j]);
	
	for (int i = 0; i < player.BULLET_COUNT; ++i)
		for (int j = 0; j < 4; ++j)
			BulletAsteroidCollision(player.bullets[i], asteroid);
	for (int i = 0; i < 1; ++i)
		for (int j = 0; j < 4; ++j)
			UltimateAsteroidCollision(player.ultimate, asteroid);
}

void GameState::draw()
{
	mat3 cam = Camera.getcameraMatrix();
	player.draw(cam);
	//player.drawHealth();
	asteroid.draw(cam);
	for (int i = 0; i < 4; ++i)
		shipchild[i].draw(cam);

}
