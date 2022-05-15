#define SDL_MAIN_HANDLED
#include <cookie.h>
#include <SDL.h>
#include <stdio.h>

using namespace Cookie;

int main(int argc, char **argv)
{
	SDL_SetMainReady();
	App app;

	while (app.running())
	{
		app.on_update();

		app.on_render();
	}

	return 0;
}