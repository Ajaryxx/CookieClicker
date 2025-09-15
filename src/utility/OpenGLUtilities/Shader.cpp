#include "PCH.hpp"
#include "utility/OpenGLUtilities/Shader.hpp"

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	m_programID = CreateProgram(vertexShaderSource, fragmentShaderSource);
}
Shader::~Shader()
{
	glDeleteProgram(m_programID);	
}
GLuint Shader::CompileShader(const char* shaderSource, GLenum type)
{
	GLuint shaderID = glCreateShader(type);
	glShaderSource(shaderID, 1, &shaderSource, 0);
	glCompileShader(shaderID);

	int32 result;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

	//Handle errors
	if (result != GL_TRUE)
	{
		int32 msgLenght;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &msgLenght);

		char* message = new char[msgLenght];

		glGetShaderInfoLog(shaderID, msgLenght, &msgLenght, message);

		spdlog::error("SHADER COMPILE ERROR: {}", message);

		delete[] message;
		message = nullptr;

		return 0;
	}
	
	return shaderID;
}
GLuint Shader::CreateProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	GLuint vertexShaderID = CompileShader(vertexShaderSource, GL_VERTEX_SHADER);
	GLuint fragmentShaderID = CompileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

	if (!vertexShaderID || !fragmentShaderID)
	{
		spdlog::error("VertexShader or/and FragmentShader have an compile error");
		return 0;
	}

	GLuint progrmID = glCreateProgram();

	glAttachShader(progrmID, vertexShaderID);
	glAttachShader(progrmID, fragmentShaderID);
	
	glLinkProgram(progrmID);

	//delete shaders
	glDetachShader(progrmID, vertexShaderID);
	glDetachShader(progrmID, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return progrmID;
}

void Shader::bind()
{
	glUseProgram(m_programID);
}
void Shader::unbind()
{
	glUseProgram(0);
}