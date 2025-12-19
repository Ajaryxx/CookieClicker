#include "PCH.hpp"
#include "Core/Window.hpp"

Window::Window(const ApplicationSpecification& spec)
{
	m_Window = new sf::RenderWindow(spec.WindowSize, spec.title, spec.style, spec.state, spec.contextSettings);
}
Window::~Window()
{

}

void Window::Loop()
{
	while (m_Window->isOpen())
	{


		m_Window->clear();


		m_Window->display();
	}
}
