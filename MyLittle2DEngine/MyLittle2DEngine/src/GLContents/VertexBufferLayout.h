#pragma once
#include <vector>
#include "VertexBufferElement.h"
class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout();
	~VertexBufferLayout();
	void Push(unsigned int type, unsigned int count, unsigned char normalized);
	void Push(unsigned int type, unsigned int count);
	inline const std::vector<VertexBufferElement>& GetElements() const
	{
		return m_Elements;
	}
	inline unsigned int GetStride() const
	{
		return m_Stride;
	}
};