#include "PCH.hpp"
#include "Core/Window.hpp"



Window::Window(const ApplicationSpecification& spec)
{
	m_Window = std::make_unique<sf::RenderWindow>(spec.WindowSize, spec.title, spec.style, spec.state, spec.contextSettings);
	m_GUIManager = std::make_unique<GUIManager>(*m_Window.get());
	m_EventManager = std::make_unique<EventManager>(m_GUIManager->GetGUI().get());
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
