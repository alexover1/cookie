#include "opengl_context.h"
#include <cookie/common.h>
#include <glad/glad.h>
#include <SDL.h>

using namespace Cookie;

OpenGLContext::OpenGLContext(SDL_Window* window)
	: m_window(window)
{
	COOKIE_ASSERT(m_window, "OpenGLContext: window is null");
}

OpenGLContext::~OpenGLContext()
{
	SDL_GL_DeleteContext(m_context);
}

void OpenGLContext::init()
{ 
	// Create SDL GL Context
	m_context = SDL_GL_CreateContext(m_window);
	if (!m_context)
	{
		Log::info("Failed to create OpenGL context: %s", SDL_GetError());
		return;
	}
	// COOKIE_ASSERT(m_context, "Failed to create OpenGL context: %s", SDL_GetError());

	SDL_GL_MakeCurrent(m_window, m_context);

	// Load Glad
	if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
	{
		Log::error("Failed to initialize glad");
	}

	Log::info("OpenGL: %s", glGetString(GL_VERSION));
	Log::info("Renderer: %s", glGetString(GL_RENDERER));
}

void OpenGLContext::swap_buffers()
{ 
	SDL_GL_SwapWindow(m_window);
}