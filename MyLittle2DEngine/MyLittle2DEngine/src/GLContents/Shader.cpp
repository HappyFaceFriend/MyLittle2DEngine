#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "GLDebug.h"
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	LoadShaders(vertexShaderPath, fragmentShaderPath);
}


Shader::~Shader()
{
	glDeleteProgram(m_Id);
}
void Shader::SetUniformMat4(const std::string& name, const glm::mat4 mat)
{
	Bind();
	glUniformMatrix4fv(GetLocation(name), 1, GL_FALSE, glm::value_ptr(mat));
}
void Shader::SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4)
{
	Bind();
	glUniform4f(GetLocation(name), v1, v2, v3, v4);
}
void Shader::SetUniform1i(const std::string& name, int v)
{
	Bind();
	glUniform1i(GetLocation(name), v);
}


int Shader::GetLocation(const std::string& name)
{
	if (m_LocationCache.find(name) != m_LocationCache.end())
		return m_LocationCache[name];
	int id = glGetUniformLocation(m_Id, name.c_str());
	if(id==-1)
		std::cout<<"Can't find uniform """<<name<<""""<<std::endl;
	return id;
}


void Shader::Bind() const
{
	GLCall(glUseProgram(m_Id));
}
void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}
std::string Shader::ParseShader(const std::string& filePath)
{
	std::ifstream stream(filePath);
	std::string code;
	if (stream.is_open())
	{
		std::stringstream sstr;
		sstr << stream.rdbuf();
		code = sstr.str();
		stream.close();
	}
	else
	{
		std::cout << "파일을 읽을 수 없음:" << filePath << std::endl;
		return 0;
	}
	return code;
}
void Shader::CompileShader(GLuint shaderID, const std::string& shaderCode)
{
	GLint result = GL_FALSE;
	const char* src = shaderCode.c_str();

	glShaderSource(shaderID, 1, &src, NULL);
	glCompileShader(shaderID);

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int infoLogLength;
		char *msg;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		msg = new char[infoLogLength + 1];
		glGetShaderInfoLog(shaderID, infoLogLength, NULL, msg);
		printf("%s\n", msg);
	}
}
void Shader::LinkShaders(GLuint vertexShaderID, GLuint fragmentShaderID)
{
	GLint result = GL_FALSE;
	m_Id = glCreateProgram();
	glAttachShader(m_Id, vertexShaderID);
	glAttachShader(m_Id, fragmentShaderID);
	glLinkProgram(m_Id);

	glGetProgramiv(m_Id, GL_LINK_STATUS, &result);
	if (result == GL_FALSE)
	{
		int infoLogLength;
		char *msg;
		glGetShaderiv(m_Id, GL_INFO_LOG_LENGTH, &infoLogLength);
		msg = new char[infoLogLength + 1];
		glGetProgramInfoLog(m_Id, infoLogLength, NULL, msg);
		printf("%s\n", msg);
	}
}
void Shader::LoadShaders(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertexShaderCode = ParseShader(vertexShaderPath);
	std::string fragmentShaderCode = ParseShader(fragmentShaderPath);

	CompileShader(vertexShaderID, vertexShaderCode);
	CompileShader(fragmentShaderID, fragmentShaderCode);

	LinkShaders(vertexShaderID, fragmentShaderID);

	glDetachShader(m_Id, vertexShaderID);
	glDetachShader(m_Id, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}
