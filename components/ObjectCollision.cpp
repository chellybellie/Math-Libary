
#include "ObjectCollision.h"
#include "collsion.h"
#include "vec-2.h"
#include <iostream>

void PlayerAstroidCollision(Playership & player, Asteroid & as)
{
	CollisionData result =
		StaticResolution(player.transform, player.rigidbody, player.collider,
						  as.transform, as.collider);
}

void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
					  as2.transform, as2.rigidbody, as2.collider);
}

void ShipChildCollision(Asteroid & as, ShipChild & sc2)
{
	StaticResolution(as.transform, as.rigidbody, as.collider,
		sc2.transform, sc2.collider);
}

void BulletAsteroidCollision(Bullet & b, Asteroid & a)
{
	
	////MAKES SURE BULLET IS ALIVE///
	if (!b.isAlive) return;

	////USE DYNAMIC TO MKAE BULLET INTERACT WITH OTHER OBJECTS////
		CollisionData result =
		StaticResolution(b.transform, b.rigidbody, b.collider,
			a.transform, a.collider);



	////SETS TIMER TO 0 SO WE CAN SHOOT BULLET AGAIN////
		if (result.penetrationDepth >= 0)
		{
			b.timer = 0;
		}

		////health subtraction for shooting asteroid////
		if (result.penetrationDepth >= 0)
		{
			a.health -= 10.f;
			printf("%d \n", a.health);
		}
		//if (a.health <= 0)
		//{
		//	a.isAlive = false;
		//	
		//}
}


void UltimateAsteroidCollision(Ultimate & U, Asteroid & a)
{
	////MAKES SURE BULLET IS ALIVE///
	if (!U.isAlive) return;

	////USE DYNAMIC TO MKAE BULLET INTERACT WITH OTHER OBJECTS////
	CollisionData result =
		StaticResolution(U.transform, U.rigidbody, U.collider,
			a.transform, a.collider);

	////health subtraction for shooting asteroid////
	if (result.penetrationDepth >= 0)
	{
		a.health -= 50.f;
		printf("%d \n \n", a.health);
	}
	Shard shard;
	if (a.health <= 0)

	////SETS TIMER TO 0 SO WE CAN SHOOT BULLET AGAIN////
	if (result.penetrationDepth >= 0)
	{
		U.timer = 0;
	}


}

void UltimateAsteroidCollision(Ultimate & U, Shard & s)
{
	////MAKES SURE BULLET IS ALIVE///
	if (!U.isAlive) return;
	
	////USE DYNAMIC TO MKAE BULLET INTERACT WITH OTHER OBJECTS////
	CollisionData result =
		DynamicResolution(U.transform, U.rigidbody, U.collider,
			s.transform, s.rigidbody, s.collider);

	////health subtraction for shooting asteroid////
	if (result.penetrationDepth >= 0)
	{
		s.health -= 50.f;

	}
	if (s.health <= 0)
	{
		s.rigidbody.force = {10,10};
	}

	////SETS TIMER TO 0 SO WE CAN SHOOT BULLET AGAIN////
	if (result.penetrationDepth >= 0)
	{
		U.timer = 0;
	}
}

void BulletAsteroidCollision(Bullet & b, Shard & s)
{
	////MAKES SURE BULLET IS ALIVE///
	if (!b.isAlive) return;

	////USE DYNAMIC TO MKAE BULLET INTERACT WITH OTHER OBJECTS////
	CollisionData result =
		DynamicResolution(b.transform, b.rigidbody, b.collider,
			s.transform, s.rigidbody, s.collider);



	////SETS TIMER TO 0 SO WE CAN SHOOT BULLET AGAIN////
	if (result.penetrationDepth >= 0)
	{
		b.timer = 0;
	}

	////health subtraction for shooting asteroid////
	if (result.penetrationDepth >= 0)
	{
		s.health -= 10.f;

	}

}

