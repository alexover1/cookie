#pragma once
#include <cookie/renderer/buffer.h>
#include <vector>
#include <memory>

namespace Cookie
{
	class COOKIE_API VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void add_vertex_buffer(const Ref<VertexBuffer>& buffer) = 0;
		virtual void set_index_buffer(const Ref<IndexBuffer>& buffer) = 0;

		virtual const std::vector<Ref<VertexBuffer>>& vertex_buffers() const = 0;
		virtual const Ref<IndexBuffer>& index_buffer() const = 0;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		static VertexArray* create();
	};
}