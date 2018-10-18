#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	void Render(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	void Render(const VertexArray& va, const Shader& shader, unsigned int count) const;
	void Clear() const;
};

