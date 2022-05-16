#include "opengl_vertexarray.h"
#include <glad/glad.h>

using namespace Cookie;

static GLenum BufferDataTypeToOpenGLBaseType(BufferDataType type)
{
	switch (type)
	{
		case BufferDataType::Float:    return GL_FLOAT;
		case BufferDataType::Float2:   return GL_FLOAT;
		case BufferDataType::Float3:   return GL_FLOAT;
		case BufferDataType::Float4:   return GL_FLOAT;
		case BufferDataType::Mat3:     return GL_FLOAT;
		case BufferDataType::Mat4:     return GL_FLOAT;
		case BufferDataType::Int:      return GL_INT;
		case BufferDataType::Int2:     return GL_INT;
		case BufferDataType::Int3:     return GL_INT;
		case BufferDataType::Int4:     return GL_INT;
		case BufferDataType::Bool:     return GL_BOOL;
	}

	COOKIE_ASSERT(false, "BufferDataType: unknown type");
	return 0;
}

OpenGLVertexArray::OpenGLVertexArray()
{
	glGenVertexArrays(1, &m_renderer_id);
}

OpenGLVertexArray::~OpenGLVertexArray()
{
	glDeleteVertexArrays(1, &m_renderer_id);
}

void OpenGLVertexArray::add_vertex_buffer(const Ref<VertexBuffer>& buffer) 
{
	COOKIE_ASSERT(buffer->layout().size(), "Vertex Buffer has no layout");

	glBindVertexArray(m_renderer_id);
	buffer->bind();

	const auto& elements = buffer->layout();
	uint offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		uint element_count = BufferElement::get_count_of_type(element.type);
		glVertexAttribPointer(i, element_count, BufferDataTypeToOpenGLBaseType(element.type), element.normalized ? GL_TRUE : GL_FALSE, buffer->stride(), (const void*)offset);
		glEnableVertexAttribArray(i);

		offset += BufferElement::get_size_of_type(element.type);
	}

	m_vertex_buffers.push_back(buffer);
}

void OpenGLVertexArray::set_index_buffer(const Ref<IndexBuffer>& buffer) 
{
	glBindVertexArray(m_renderer_id);
	buffer->bind();

	m_index_buffer = buffer;
}

void OpenGLVertexArray::bind() const
{
	glBindVertexArray(m_renderer_id);
}

void OpenGLVertexArray::unbind() const
{
	glBindVertexArray(0);
}