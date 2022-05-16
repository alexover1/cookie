#include <cookie/renderer/buffer.h>
#include <cookie/renderer/renderer.h>

#include "../platform/opengl/opengl_buffer.h"

using namespace Cookie;

VertexBuffer* VertexBuffer::create(float* vertices, u32 size)
{
	switch (Renderer::api())
	{
	case RendererAPI::None: COOKIE_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;
	case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
	}

	COOKIE_ASSERT(false, "Renderer::API is not set");
	return nullptr;
}

IndexBuffer* IndexBuffer::create(u32* indices, u32 size)
{
	switch (Renderer::api())
	{
	case RendererAPI::None: COOKIE_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;
	case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
	}

	COOKIE_ASSERT(false, "Renderer::API is not set");
	return nullptr;
}