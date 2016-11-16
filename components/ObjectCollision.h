#pragma once

#include "Playership.h"
#include "Asteroid.h"
#include "Bullets.h"

void PlayerAstroidCollision(Playership &player, Asteroid &as);
void AsteroidCollision(Asteroid &as1, Asteroid &as2);
void BulletAsteroidCollision(Bullet &b, Asteroid &a);