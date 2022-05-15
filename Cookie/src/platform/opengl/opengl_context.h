#pragma once
#include <cookie/renderer/graphicscontext.h>
#include <SDL.h>

// class SDL_Window;
// class SDL_GLContext;

namespace Cookie
{
	class OpenGLContext : public GraphicsContext
	{
	private:
		SDL_Window* m_window;
		SDL_GLContext m_context;
	
	public:
		OpenGLContext(SDL_Window* window);
		~OpenGLContext();

		virtual void init() override;
		virtual void swap_buffers() override;
	};
}