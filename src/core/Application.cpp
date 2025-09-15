#include "PCH.hpp"
#include "core/Application.hpp"
#include "core/Window.hpp"
#include "stb_image.h"

Application::Application(const WindowParameters& windowParameter)
{
	m_AppWindow = std::make_unique<Window>(windowParameter);
}

Application::~Application()
{

}
bool Application::Init()
{
	//flip stbi
	stbi_set_flip_vertically_on_load(true);
	const bool succses = m_AppWindow->Init();

#ifdef ENABLE_OPENGL_DEBUG

	//enable debug for OpenGL messages
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(&Application::OpenGLCallback, nullptr);

#endif // ENABLE_OPENGL_DEBUG

	return succses;
}
void Application::Run()
{
	m_AppWindow->Loop();
}

void Application::OpenGLCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	if (severity == GL_DEBUG_SEVERITY_NOTIFICATION && (filter & NOTIFICATION))
	{
		spdlog::info("OpenGL notification info: {}", message);
	}
	if (severity == GL_DEBUG_SEVERITY_LOW && (filter & LOW))
	{
		spdlog::warn("OpenGL low severity info: {}", message);
	}
	if (severity == GL_DEBUG_SEVERITY_MEDIUM && (filter & MEDIUM))
	{
		spdlog::warn("OpenGL medium severity info: {}", message);
	}
	if (severity == GL_DEBUG_SEVERITY_HIGH && (filter & HIGH))
	{
		spdlog::critical("OpenGL high severity info: {}", message);
	}
	
}

void Application::SetFillterDebug(SeverityFilter filter)
{
	this->filter = filter;
}
