
#include "ObjectCollision.h"
#include "collsion.h"
#include "vec-2.h"


#include <iostream>

void PlayerAstroidCollision(Playership & player, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
						  as.transform, as.rigidbody, as.collider);

	////penatly for hitting objects////
	if (result.penetrationDepth >= 0)
	{////TO:DO/////
 		player.health - .5f;
	}

}

void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
					  as2.transform, as2.rigidbody, as2.collider);
}

void BulletAsteroidCollision(Bullet & b, Asteroid & a)
{
	////MAKES SURE BULLET IS ALIVE///
	if (!b.isAlive) return;

	////USE DYNAMIC TO MKAE BULLET INTERACT WITH OTHER OBJECTS////
		CollisionData result =
		DynamicResolution(b.transform, b.rigidbody, b.collider,
			a.transform, a.rigidbody, a.collider);



	////SETS TIMER TO 0 SO WE CAN SHOOT BULLET AGAIN////
		if (result.penetrationDepth >= 0)
		{
			b.timer = 0;
		}


}
