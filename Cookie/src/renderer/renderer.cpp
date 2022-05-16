#include <cookie/renderer/renderer.h>
#include <glad/glad.h> // TODO: REMOVE THIS, THIS IS SO I CAN CALL GLDRAWELEMENTS IN SANDBOX

using namespace Cookie;

RendererAPI Renderer::s_renderer_api = RendererAPI::None;

// TODO: REMOVE THIS, THIS IS SO I CAN CALL GLDRAWELEMENTS IN SANDBOX
void Renderer::draw_indexed(const Ref<VertexArray>& vertex_array)
{
	vertex_array->bind();
	glDrawElements(GL_TRIANGLES, vertex_array->index_buffer()->count(), GL_UNSIGNED_INT, nullptr);
}