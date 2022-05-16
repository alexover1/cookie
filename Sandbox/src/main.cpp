#include <cookie.h>

using namespace Cookie;

namespace
{
	Ref<VertexArray> vertex_array;
}

int main(int argc, char* argv[])
{
	Jar jar;

	float vertices[] = 
	{
		 0.5f, 	0.5f, 1, 1,
		 0.5f, -0.5f, 1, 1,
		-0.5f, -0.5f, 1, 1,
		-0.5f,  0.5f, 1, 1
	};
	u32 indices[6] = { 0, 1, 2, 2, 3, 0 };

	// vertex array
	vertex_array.reset(VertexArray::create());

	// vertex buffer
	Ref<VertexBuffer> vertex_buffer;
	vertex_buffer.reset(VertexBuffer::create(vertices, sizeof(vertices)));
	vertex_buffer->push_layout<BufferDataType::Float2>();
	vertex_buffer->push_layout<BufferDataType::Float2>();
	vertex_array->add_vertex_buffer(vertex_buffer);

	// index buffer
	Ref<IndexBuffer> index_buffer;
	index_buffer.reset(IndexBuffer::create(indices, sizeof(indices) / sizeof(u32)));
	vertex_array->set_index_buffer(index_buffer);

	while (jar.alive())
	{
		jar.events();

		Renderer::draw_indexed(vertex_array);

		jar.render();
	}

	return 0;
}