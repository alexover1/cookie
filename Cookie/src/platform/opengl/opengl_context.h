#pragma once
#include <cookie/renderer/graphicscontext.h>

struct SDL_Window;

namespace Cookie
{
	class OpenGLContext : public GraphicsContext
	{
	private:
		SDL_Window* m_window;
		void* m_context;
	
	public:
		OpenGLContext(SDL_Window* window);
		~OpenGLContext();

		virtual void init() override;
		virtual void swap_buffers() override;
	};
}