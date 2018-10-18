#include "IndexBuffer.h"
#include <GL/glew.h>
#include "GLDebug.h"

IndexBuffer::IndexBuffer(const unsigned int* datas, unsigned int count)
{
	GLCall(glGenBuffers(1, &m_Id));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id));	//이 버퍼를 그려라
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), datas, GL_STATIC_DRAW));
	m_Count = count;
}
IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_Id));
}
void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id));
}
void IndexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
