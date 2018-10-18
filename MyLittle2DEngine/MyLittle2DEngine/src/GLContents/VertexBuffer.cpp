#include "VertexBuffer.h"
#include <GL/glew.h>
#include "GLDebug.h"
VertexBuffer::VertexBuffer(unsigned int size, const void * data)
{
	GLCall(glGenBuffers(1, &m_Id));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_Id));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_Id);
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_Id));
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
