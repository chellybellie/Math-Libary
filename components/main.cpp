#include "sfwdraw.h"
#include "vec-2.h"
#include "transform.h"
#include "flops.h"
using namespace sfw;
void main()
{
	sfw::initContext();
	Transform trans(400, 300);
	int j = int(4);
	int k(4);
	int l = { 4 };
	int n{ 4 };

	Transform tl = Transform(400, 300);
	Transform tn = { 400, 300 };
	Transform tm(400, 300);
	Transform tq{ 400,300 };

	//trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	vec2 basis = { 40,0 };
	float ang_vec = 0;
	trans.facing = 0;

	while (sfw::stepContext())
	{
		trans.facing += getDeltaTime();
		vec2 incident = fromangle(ang_vec) * 40;
		float proj = dot(basis, incident);
		//trans.debugDraw();
	}
	sfw::termContext();
}