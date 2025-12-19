#pragma once
#include "Core/GameValues.hpp"

class Window
{
public:
	Window(const ApplicationSpecification& spec);
	~Window();


	void Loop();
private:

	sf::RenderWindow* m_Window = nullptr;

};