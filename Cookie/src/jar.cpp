#include <cookie/jar.h>
#include <cookie/common.h>
#include "internal/internal.h"

using namespace Cookie;

namespace
{ 
	SDL_Window* window;
	void* ctx;
}

Jar::Jar(const char* name, int width, int height, int options)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		Log::error("Failed to initialize SDL");
		kill();
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// window flags
	int flags = 0;
	if (options & COOKIE_OPT_OPENGL) flags |= SDL_WINDOW_OPENGL;
	if (options & COOKIE_OPT_FULLSCREEN) flags |= SDL_WINDOW_FULLSCREEN;
	if (options & COOKIE_OPT_RESIZEABLE) flags |= SDL_WINDOW_RESIZABLE;
	if (options & COOKIE_OPT_HIDDEN) flags |= (SDL_WINDOW_HIDDEN | SDL_WINDOW_MINIMIZED);

	window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	COOKIE_ASSERT(window != nullptr, "Failed to create window");

	// Init OpenGL
	ctx = Internal::gl_context_create(window);
	Internal::gl_context_make_current(window, ctx);
	Internal::gl_init();
}

Jar::~Jar()
{
	if (window != nullptr)
		SDL_DestroyWindow(window);
	window = nullptr;

	Internal::gl_context_destroy(ctx);

	SDL_Quit();
}

void Jar::events()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			kill();
			break;
		}
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Jar::render()
{
	SDL_GL_SwapWindow(window);
}

void Jar::imgui_render()
{
	
}