#include "Renderer.h"
#include "GLDebug.h"

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::Render(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	va.Bind();
	ib.Bind();
	shader.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
void Renderer::Render(const VertexArray& va, const Shader& shader, unsigned int count) const
{
	va.Bind();
	shader.Bind();
	glDrawArrays(GL_TRIANGLES, 0, count);
}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}