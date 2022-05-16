#include <cookie/renderer/vertexarray.h>
#include <cookie/renderer/renderer.h>

#include "../platform/opengl/opengl_vertexarray.h"

using namespace Cookie;

VertexArray* VertexArray::create()
{
	switch (Renderer::api())
	{
	case RendererAPI::None: COOKIE_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;
	case RendererAPI::OpenGL: return new OpenGLVertexArray();
	}

	COOKIE_ASSERT(false, "Renderer::API is not set");
	return nullptr;
}