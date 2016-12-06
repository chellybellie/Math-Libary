#include "gamestate.h"
#include "ObjectCollision.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include <iostream>
#include "SHARDS.h"

void GameState::play()
{
	player.transform.m_position = vec2{ 200,100 };
	player.transform.m_facing = 0;
	
	asteroid.transform.m_position = (vec2{ 200,1000 });
	asteroid.rigidbody.drag = 1;

	/////////// attaching spacechildren to "mothership"  //////////
	////////// adding offset timers for animation effects//////////

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
	asteroid.update(deltatime, *this);
	
	
	
	
	for (int i = 0; i < SHARD_COUNT; ++i)
	{
		shards[i].update(deltatime, *this);
	}

	for (int j = 0; j < SHARD_COUNT; ++j)
		for (int i = 0; i < player.BULLET_COUNT; ++i)
			BulletAsteroidCollision(player.bullets[i], shards[j]);

	for (int i = 0; i < 4; ++i)
		shipchild[i].update(deltatime, *this);

	PlayerAstroidCollision(player, asteroid);
	
	for (int i = 0; i < 4 ; ++i)
			ShipChildCollision(asteroid, shipchild[i]);

		for (int i = 0; i < player.BULLET_COUNT; ++i)
			BulletAsteroidCollision(player.bullets[i], asteroid);

			UltimateAsteroidCollision(player.ultimate, asteroid);

		
}

void GameState::draw()
{
	mat3 cam = Camera.getcameraMatrix();
	player.draw(cam);

	if (asteroid.isAlive)
		asteroid.draw(cam);


	for (int i = 0; i < 4; ++i)
		shipchild[i].draw(cam);

	for (int i = 0; i < SHARD_COUNT; ++i)
		if(shards[i].isAlive)
			shards[i].draw(cam);

}
