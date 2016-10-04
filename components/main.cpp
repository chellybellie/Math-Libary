#include "sfwdraw.h"
#include "vec-2.h"
#include "transform.h"
#include "flops.h"
#include <cmath>
using namespace sfw;
void main()
{
	
	Transform trans(400, 300);
	int j = int(4);
	int k(4);
	int l = { 4 };
	int n{ 4 };

	Transform tl = Transform(400, 300);
	Transform tn = { 400, 300 };
	Transform tm(400, 300);
	Transform tq{ 400,300 };

	trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	vec2 basis = { 40,0 };
	float ang_vec = 0;
	trans.facing = 0;
		float W = 1200, H = 1200;
		sfw::initContext(W,H);
	while (sfw::stepContext())
	{

		
		for (int i = 0; i < 100; ++i)
		{
			
			float t1 = i / 100.f;// 0-1 range.			
			float t2 = (i + 1) / 100.f;
			vec2 v1 = quadBezier(.5f, 0, 1, t1);
			vec2 v2 = quadBezier(.5f, 0, 1, t2);

	
			t1 *= W;
			v1 *= H;
			t2 *= W;
			v2 *= H;
			sfw::drawLine(t1, v1, t2, v2);
		
		}
	}

	//	float x = sfw::getDeltaTime();
	//	if (x > 1) x = 0;
		//float bounce = cosf(x * 10)*(1 - x);

		
		trans.facing += getDeltaTime();
		vec2 incident = fromangle(ang_vec) * 40;
		float proj = dot(basis, incident);
		trans.debugDraw();

	sfw::termContext();
}

