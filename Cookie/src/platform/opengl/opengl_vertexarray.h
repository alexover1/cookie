#pragma once
#include <cookie/renderer/vertexarray.h>

namespace Cookie
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void add_vertex_buffer(const Ref<VertexBuffer>& buffer) override;
		void set_index_buffer(const Ref<IndexBuffer>& buffer) override;

		const std::vector<Ref<VertexBuffer>>& vertex_buffers() const { return m_vertex_buffers; } 
		const Ref<IndexBuffer>& index_buffer() const { return m_index_buffer; }

		void bind() const override;
		void unbind() const override;

	private:
		u32 m_renderer_id;
		std::vector<Ref<VertexBuffer>> m_vertex_buffers;
		Ref<IndexBuffer> m_index_buffer;
	};
}