#include "Ultimate wepon.h"
#include "gamestate.h"
#include "sfwdraw.h"



Ultimate::Ultimate()
{
	vec2 hullverts[] = { { -.5f,0 },{ 0,1.f },{ .5f,0 },{ 0,-1.f } };
	collider = Collider(hullverts, 4);
	transform.m_scale = vec2{ 30,30 };
	rigidbody.mass = 15;


}


void Ultimate::update(float deltatime, GameState & gs)
{
	////UPDATE ME/////
	
	if (!isAlive) return;

	rigidbody.integrate(transform, deltatime);

	timer -= deltatime;
	isAlive = timer > 0;
}
void Ultimate::draw(const mat3 & camera)
{
	if (!isAlive) return;

	transform.debugDraw(camera);

	collider.DebugDraw(camera, transform);
}
void Ultimate::drawEffect1(Transform & planeTrans, const mat3 & T)
{
	mat3 glob = T * planeTrans.getGlobalTransform();

	vec3 L1 = glob * vec3{ 9,2 ,1 };
	vec3 L2 = glob *vec3{ 11,4 ,1 };
	vec3 L3 = glob *vec3{ 10,-3 ,1 };
	vec3 L4 = glob *vec3{ 15,0 ,1 };

	vec3 QL1 = glob * vec3{ -3,-18 ,1 };
	vec3 QL2 = glob * vec3{ -5,-13 ,1 };
	vec3 QL3 = glob * vec3{ -7,-11 ,1 };
	vec3 QL4 = glob * vec3{ -11,-15 ,1 };
	vec3 QL5 = glob * vec3{ -13,-9 ,1 };

	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, RED);
	sfw::drawLine(L2.x, L2.y, L3.x, L3.y, RED);
	sfw::drawLine(L3.x, L3.y, L4.x, L4.y, RED);

	sfw::drawLine(QL1.x, QL1.y, QL2.x, QL2.y, RED);
	sfw::drawLine(QL2.x, QL2.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL4.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL5.y, QL3.x, QL5.y, RED);
}
void Ultimate::drawEffect0(Transform & planeTrans, const mat3 & T)
{
	mat3 glob = T * planeTrans.getGlobalTransform();

	vec3 L1 = glob * vec3{ 10,3 ,1 };
	vec3 L2 = glob *vec3{ 12,6 ,1 };
	vec3 L3 = glob *vec3{ 15,2 ,1 };

	vec3 LL1 = glob * vec3{ 8,-14 ,1 };
	vec3 LL2 = glob * vec3{ 1,-16 ,1 };
	vec3 LL3 = glob * vec3{ 5,-24 ,1 };

	vec3 QL1 = glob * vec3{ -9,-15 ,1 };
	vec3 QL2 = glob * vec3{ -15,-6 ,1 };
	vec3 QL3 = glob * vec3{ -18,8 ,1 };
	vec3 QL4 = glob * vec3{ -7,14 ,1 };

	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, RED);
	sfw::drawLine(L2.x, L2.y, L3.x, L3.y, RED);

	sfw::drawLine(LL1.x, LL1.y, LL2.x, LL2.y, RED);
	sfw::drawLine(LL2.x, LL2.y, LL3.x, LL3.y, RED);

	sfw::drawLine(QL1.x, QL1.y, QL2.x, QL2.y, RED);
	sfw::drawLine(QL2.x, QL2.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL4.y, QL3.x, QL3.y, RED);
}
void Ultimate::drawEffect2(Transform & planeTrans, const mat3 & T)
{
	mat3 glob = T * planeTrans.getGlobalTransform();

	vec3 L1 = glob * vec3{ 0,12 ,1 };
	vec3 L2 = glob *vec3{ 3,15 ,1 };
	vec3 L3 = glob *vec3{ -2,17 ,1 };
	vec3 L4 = glob *vec3{ -8,13 ,1 };

	vec3 LL1 = glob * vec3{ 10,-4 ,1 };
	vec3 LL2 = glob * vec3{ 15,-8 ,1 };
	vec3 LL3 = glob * vec3{ 0,-17 ,1 };
	vec3 LL4 = glob * vec3{ 11,-18 ,1 };

	vec3 QL1 = glob * vec3{ -13,-1 ,1 };
	vec3 QL2 = glob * vec3{ -12,2 ,1 };
	vec3 QL3 = glob * vec3{ -15,6 ,1 };
	vec3 QL4 = glob * vec3{ -18,0 ,1 };
	vec3 QL5 = glob * vec3{ -16,-4 ,1 };

	sfw::drawLine(L1.x, L1.y, L2.x, L2.y, RED);
	sfw::drawLine(L2.x, L2.y, L3.x, L3.y, RED);
	sfw::drawLine(L4.x, L4.y, L3.x, L3.y, RED);

	sfw::drawLine(LL1.x, LL1.y, LL2.x, LL2.y, RED);
	sfw::drawLine(LL2.x, LL2.y, LL3.x, LL3.y, RED);
	sfw::drawLine(LL4.x, LL4.y, LL3.x, LL3.y, RED);

	sfw::drawLine(QL1.x, QL1.y, QL2.x, QL2.y, RED);
	sfw::drawLine(QL2.x, QL2.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL4.y, QL3.x, QL3.y, RED);
	sfw::drawLine(QL4.x, QL4.y, QL5.x, QL5.y, RED);

}