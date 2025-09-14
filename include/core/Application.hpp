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
private:

	std::unique_ptr<Window> m_AppWindow;
};