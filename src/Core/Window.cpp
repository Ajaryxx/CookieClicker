#include "PCH.hpp"
#include "Core/Window.hpp"
#include "Utility/HelperMacros.hpp"

Window::Window(const WindowParameters& specification)
{
	m_Specification = specification;

	m_Window = sf::RenderWindow(
		m_Specification.WindowSize,
		m_Specification.title,
		m_Specification.style,
		m_Specification.state,
		m_Specification.ContextSettings);
}
Window::~Window()
{
}

void Window::Loop()
{
	while (m_Window.isOpen())
	{
		m_Window.clear();

		m_Window.display();
	}
}