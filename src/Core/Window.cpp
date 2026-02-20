#include "PCH.hpp"
#include "Core/Window.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"


using namespace CC;

Window::Window(const WindowParameters& specification)
{
	m_Specification = specification;

	m_Window = sf::RenderWindow(
		m_Specification.WindowSize,
		m_Specification.title,
		m_Specification.style,
		m_Specification.state,
		m_Specification.ContextSettings);

	m_Window.setVerticalSyncEnabled(m_Specification.vSync);
	m_Window.setFramerateLimit(m_Specification.fpsLimit);
	m_Window.setMinimumSize(std::optional<sf::Vector2u>({400, 300}));

	m_GUIManager = std::make_unique<GUIManager>(m_Window);

}
Window::~Window()
{
}

void CC::Window::PollEvents()
{
	std::optional<sf::Event> evt = m_Window.pollEvent();
	while(const auto& evt = m_Window.pollEvent())
	{
		EventSystem::Get().UpdateEvents(evt);
		m_GUIManager->UpdateGUIEvents(evt);
	}
}

void CC::Window::CloseWindow()
{
	m_Window.close();
}

void CC::Window::Render(const std::vector<LayerSpecification>& layers)
{
	m_Window.clear();

	for(const auto& layer : layers)
	{
		for(const auto& drawable : layer.layer->GetDrawables())
		{
			m_Window.draw(*drawable);
		}
	}
	m_GUIManager->RenderGUI();
	m_Window.display();
}
