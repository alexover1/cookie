#include <cookie/app.h>
#include <cookie/common.h>
#include "internal/internal.h"

using namespace Cookie;

namespace
{ 
	SDL_Window* window;
	void* ctx;
}

App::App()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		Log::error("Failed to initialize SDL");
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// window flags
	// u32 flags = 0;
	int flags = SDL_WINDOW_OPENGL;
	// if (options & FLUF_APP_OPTIONS_OPENGL_CONTEXT) flags |= SDL_WINDOW_OPENGL;
	// if (options & FLUF_APP_OPTIONS_FULLSCREEN) flags |= SDL_WINDOW_FULLSCREEN;
	// if (options & FLUF_APP_OPTIONS_RESIZABLE) flags |= SDL_WINDOW_RESIZABLE;
	// if (options & FLUF_APP_OPTIONS_HIDDEN) flags |= (SDL_WINDOW_HIDDEN | SDL_WINDOW_MINIMIZED);

	window = SDL_CreateWindow("Cat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, flags);
	COOKIE_ASSERT(window != nullptr, "Failed to create window");

	// Init OpenGL
	ctx = Internal::gl_context_create(window);
	Internal::gl_context_make_current(window, ctx);
	Internal::gl_init();

	m_running = true;
}

App::~App()
{
	if (window != nullptr)
		SDL_DestroyWindow(window);
	window = nullptr;

	Internal::gl_context_destroy(ctx);

	SDL_Quit();
}

void App::on_update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			stop_running();
			break;
		}
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void App::on_render()
{
	SDL_GL_SwapWindow(window);
}

void App::on_imgui_render()
{
	
}