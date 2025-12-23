#include "PCH.hpp"
#include "Core/GameWindow.hpp"


GameWindow::GameWindow(const ApplicationSpecification& spec)
{
	m_Window = std::make_unique<sf::RenderWindow>(spec.WindowSize, spec.title, spec.style, spec.state, spec.contextSettings);
	m_GUIManager = std::make_unique<GUIManager>(*m_Window);
	m_EventManager = std::make_unique<EventManager>(&m_GUIManager->GetGUI());
}
GameWindow::~GameWindow()
{

}

void GameWindow::Loop()
{
	while (m_Window->isOpen())
	{
		m_EventManager->UpdateEvents();
		
		m_Window->clear();


		m_Window->display();
	}
}
