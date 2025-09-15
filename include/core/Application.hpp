#pragma once
#include "utility/GameValueDefines.hpp"

class Window;

class Application
{
public:
	Application(const WindowParameters& windowParameter);
	~Application();

	//Initzializes SDL and OpenGL context and spdlog
	bool Init();

	void Run();
	void SetFillterDebug(SeverityFilter filter);
	static void OpenGLCallback(GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam);

private:

	std::unique_ptr<Window> m_AppWindow;

	inline static SeverityFilter filter = SeverityFilter::ALL;
};