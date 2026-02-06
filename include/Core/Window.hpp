#pragma once
#include "BaseValues.hpp"

class Window
{
public:
	Window(const WindowParameters& specification);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	void Loop();

private:

	sf::RenderWindow m_Window;
	WindowParameters m_Specification;
};