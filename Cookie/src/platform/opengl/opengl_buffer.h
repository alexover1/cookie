#pragma once
#include <cookie/renderer/buffer.h>

namespace Cookie
{
	class OpenGLVertexBuffer : public VertexBuffer 
	{
	public:
		OpenGLVertexBuffer(float* vertices, u32 size);
		~OpenGLVertexBuffer();

		void bind() const;
		void unbind() const;

	private:
		u32 m_renderer_id;
	};

	class OpenGLIndexBuffer : public IndexBuffer 
	{
	public:
		OpenGLIndexBuffer(u32* indices, u32 count);
		~OpenGLIndexBuffer();

		virtual uint count() const { return m_count; }

		void bind() const;
		void unbind() const;

	private:
		u32 m_renderer_id;
		uint m_count;
	};
}