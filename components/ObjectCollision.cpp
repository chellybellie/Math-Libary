
#include "ObjectCollision.h"
#include "collsion.h"
#include "vec-2.h"




void PlayerAstroidCollision(Playership & player, Asteroid & as)
{
	CollisionData result =
		DynamicResolution(player.transform, player.rigidbody, player.collider,
						  as.transform, as.rigidbody, as.collider);

	////penatly for hitting objects////
	if (result.penetrationDepth >= 0)
	{
 		player.health - .5f;
	}

}

void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
					  as2.transform, as2.rigidbody, as2.collider);
}
