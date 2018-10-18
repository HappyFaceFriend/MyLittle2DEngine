#include "VertexArray.h"
#include <GL/glew.h>
#include "GLDebug.h"

VertexArray::VertexArray() : m_IndexCount(0)
{
	glGenVertexArrays(1, &m_Id);
	glBindVertexArray(m_Id);
}
void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
	Bind();
	const auto& elements = layout.GetElements();
	unsigned int stride = layout.GetStride();
	unsigned int offset = 0;
	vb.Bind();
	for (int i = 0; i < elements.size(); i++)
	{
		GLCall(glEnableVertexAttribArray(m_IndexCount+i));
		GLCall(glVertexAttribPointer(m_IndexCount+i, elements[i].count, elements[i].type, elements[i].normalized, stride, (const void*)offset));
		offset += elements[i].count * VertexBufferElement::GetTypeSize(elements[i].type);

	}
	m_IndexCount += elements.size();
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_Id);
}
void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_Id);
}
