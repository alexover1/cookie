#pragma once
#include <cookie/common.h>
#include <glad/glad.h>
#include <SDL.h>

namespace Cookie
{ 
	namespace Internal
	{ 
		void* gl_context_create(SDL_Window* window)
		{ 
			void* pointer = SDL_GL_CreateContext(window);
			if (pointer == nullptr)
			{
				Log::info("Failed to create OpenGL context: %s", SDL_GetError());
			}
			return pointer;
		}

		void gl_context_make_current(SDL_Window* window, void* context)
		{ 
			SDL_GL_MakeCurrent(window, context);
		}

		void gl_context_destroy(void* context)
		{ 
			SDL_GL_DeleteContext(context);
		}

		void gl_init()
		{ 
			if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
			{
				Log::error("Failed to initialize glad");
			}

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glClearColor(0, 0, 0, 1);

			Log::info("OpenGL v%s", glGetString(GL_VERSION));
			Log::info("Renderer: %s", glGetString(GL_RENDERER));
		}
	}
}