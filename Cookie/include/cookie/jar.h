#pragma once
#include <cookie/common.h>
#include <cookie/renderer/graphicscontext.h>

namespace Cookie
{
	class COOKIE_API Jar 
	{
	private:
		bool m_alive = true;
		GraphicsContext* m_context;

	public:
		Jar(const char* name = "My Jar", int width = 1280, int height = 720, int options = COOKIE_DEFAULT_OPTS_OPENGL);
		~Jar();

		void events();
		void render();
		void imgui_render();

		static constexpr int COOKIE_DEFAULT_OPTS_OPENGL = COOKIE_OPT_OPENGL | COOKIE_OPT_RESIZEABLE | COOKIE_OPT_CENTERED;

		inline bool alive() const { return m_alive; }
		inline void kill() { m_alive = false; }
	};
}