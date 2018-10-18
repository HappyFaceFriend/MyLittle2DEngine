#pragma once
#include <GL/glew.h>
#include <iostream>
struct VertexBufferElement
{
	unsigned int count;
	unsigned int type;
	unsigned char normalized;
	VertexBufferElement(unsigned int count, unsigned int type, unsigned char normaized) :
		count(count), type(type), normalized(normalized) {}
	static unsigned int GetTypeSize(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT: return sizeof(GLfloat);
		case GL_UNSIGNED_INT:	return sizeof(GLuint);
		case GL_UNSIGNED_BYTE:	return sizeof(GLbyte);
		}
		std::cout << "Unknown Type" << std::endl;
		return 0;
	}
};