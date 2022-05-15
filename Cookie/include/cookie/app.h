#pragma once
#include <cookie/common.h>

namespace Cookie
{
	class COOKIE_EXPORT App
	{
	private:
		bool m_running;

		inline void stop_running() { m_running = false; }

	public:
		App();
		~App();

		void on_update();
		void on_render();
		void on_imgui_render();

		inline bool running() const { return m_running; }
	};
}