#pragma once
#include "utility/GameValueDefines.hpp"

class Window
{
public:
	Window(const WindowParameters& windowParameter) : m_WindowParameters(windowParameter), m_Window(nullptr), m_GLContext(nullptr) {};
	~Window();

	Window(const Window&) = delete;
	Window(Window&&) = delete;

	Window& operator=(const Window&) = delete;
	Window& operator=(Window&&) = delete;

	//returns false when creating a context or window fails
	bool Init();
	void Loop();

private:

	void SetAllOpenGLWindowAttributes();

private:
	WindowParameters m_WindowParameters;

	SDL_Window* m_Window = nullptr;
	SDL_GLContext m_GLContext = nullptr;

	bool ShouldLoop = true;
};