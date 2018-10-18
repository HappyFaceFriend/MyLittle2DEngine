#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout() : m_Stride(0)
{
}
VertexBufferLayout::~VertexBufferLayout()
{
}
void VertexBufferLayout::Push(unsigned int type, unsigned int count, unsigned char normalized)
{
	m_Elements.emplace_back(count, type, normalized);
	m_Stride += count*VertexBufferElement::GetTypeSize(type);
}
void VertexBufferLayout::Push(unsigned int type, unsigned int count)
{
	m_Elements.emplace_back(count, type, GL_FALSE);
	m_Stride += count*VertexBufferElement::GetTypeSize(type);
}