#pragma once
#include <cookie/renderer/vertexarray.h>

namespace Cookie
{
	enum class RendererAPI
	{
		None = 0,
		OpenGL = 1,
		Direct3D = 2,
		Vulkan = 3,
		Metal = 4,
	};

	class Renderer
	{
	public:
		inline static RendererAPI api() { return s_renderer_api; }
		inline static void set_api(RendererAPI api) { s_renderer_api = api; }

		COOKIE_API static void draw_indexed(const Ref<VertexArray>& vertex_array);
		
	private:
		static RendererAPI s_renderer_api;
	};
}