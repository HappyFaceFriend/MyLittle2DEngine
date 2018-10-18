#pragma once
#include <map>
#include <string>
#include <GL/glew.h>
#include <glm\glm.hpp>
class Shader
{
private:
	unsigned int m_Id;
	std::map<std::string, int> m_LocationCache;

public:
	Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniformMat4(const std::string& name, const glm::mat4 mat);
	void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);
	void Shader::SetUniform1i(const std::string& name, int v);
private:
	std::string ParseShader(const std::string& filePath);
	void CompileShader(GLuint shaderID, const std::string& shaderCode);
	void LinkShaders(GLuint vertexShaderID, GLuint fragmentShaderID);
	void LoadShaders(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	int GetLocation(const std::string& name);
};

