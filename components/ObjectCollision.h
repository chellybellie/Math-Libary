#pragma once

#include "Playership.h"
#include "Asteroid.h"
#include "Bullets.h"
#include "spaceship Child.h"
#include "SHARDS.h"

void PlayerAstroidCollision(Playership &player, Asteroid &as);
void AsteroidCollision(Asteroid &as1, Asteroid &as2);
void BulletAsteroidCollision(Bullet &b, Asteroid &a);

void ShipChildCollision(Asteroid & as, ShipChild & sc2);
void UltimateAsteroidCollision(Ultimate & U, Asteroid & a);
void UltimateAsteroidCollision(Ultimate & U, Shard & s);
void BulletAsteroidCollision(Bullet &b, Shard &s);
