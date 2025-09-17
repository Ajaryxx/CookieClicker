#pragma once
#include "utility/GameValueDefines.hpp"

class Shader
{
public:
	Shader(const char* vertexShaderSource, const char* fragmentShaderSource);
	~Shader();

	void bind();
	void unbind();

	inline GLuint GetShaderID() const
	{
		return m_programID;
	}
private:


	GLuint CompileShader(const char* shaderSource, GLenum type);
	GLuint CreateProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

	GLuint m_programID;
};