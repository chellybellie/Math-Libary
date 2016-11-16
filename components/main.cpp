#include "sfwdraw.h"
#include "gamestate.h"

void main()
{
	float W = 1200, H = 1200;
	sfw::initContext(W, H);

	GameState game;

	game.play();

		while (sfw::stepContext())
		{
			float dt = sfw::getDeltaTime();

			game.update(dt);

			game.draw();

		}
		sfw::termContext();
	
}

