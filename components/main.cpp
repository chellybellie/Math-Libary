#include "sfwdraw.h"
#include "vec-2.h"
#include "transform.h"
using namespace sfw;
void main()
{
	sfw::initContext();
	Transform trans;

	trans.position = vec2{ 400,300 };
	trans.facing = 0;
	while (sfw::stepContext())
	{
		trans.facing += getDeltaTime();
		trans.debugDraw();
	}
	sfw::termContext();
}