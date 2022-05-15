#include <cookie/jar.h>
#include <cookie/common.h>
#include "platform/opengl/opengl_context.h"
#include "internal/internal.h"

using namespace Cookie;

namespace
{ 
	SDL_Window* window;
}

Jar::Jar(const char* name, int width, int height, int options)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		Log::error("Failed to initialize SDL");
		kill();
		return;
	}

	// Set OpenGL attributes
	if (options & COOKIE_OPT_OPENGL)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	}
	
	// Set window flags
	int flags = 0;
	if (options & COOKIE_OPT_OPENGL) flags |= SDL_WINDOW_OPENGL;
	if (options & COOKIE_OPT_FULLSCREEN) flags |= SDL_WINDOW_FULLSCREEN;
	if (options & COOKIE_OPT_RESIZEABLE) flags |= SDL_WINDOW_RESIZABLE;
	if (options & COOKIE_OPT_HIDDEN) flags |= (SDL_WINDOW_HIDDEN | SDL_WINDOW_MINIMIZED);

	// Create the window
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	COOKIE_ASSERT(window != nullptr, "Failed to create window");

	// OpenGL context
	if (options & COOKIE_OPT_OPENGL)
	{
		m_context = new OpenGLContext(window);
	}
	
	// D3D11 context
	if (options & COOKIE_OPT_D3D11)
	{
		// TODO: Implement D3D11 context
	}

	// Initialize context
	COOKIE_ASSERT(m_context != nullptr, "Did not create context");
	m_context->init();
}

Jar::~Jar()
{
	if (window != nullptr)
		SDL_DestroyWindow(window);
	window = nullptr;

	if (m_context != nullptr)
		delete m_context;
	m_context = nullptr;

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
}

void Jar::render()
{
	m_context->swap_buffers();
}

void Jar::imgui_render()
{
	
}