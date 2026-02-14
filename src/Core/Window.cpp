#include "PCH.hpp"
#include "Core/Window.hpp"
#include "Game/GameManager.hpp"
#include "Core/GUIManager.hpp"

using namespace CC;

Window::Window(const WindowParameters& specification, std::function<void(const std::optional<sf::Event>&)> EventUpdateFunc)
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

	CCASSERT(EventUpdateFunc, "EVENT_UPDATE_FUNC HAS TO BE A VALID PTR");
	m_EventUpdateFunc = EventUpdateFunc;

	GUIManager::Get().InitGUIManager(m_Window);

}
Window::~Window()
{
}

void Window::Loop()
{
	tgui::Gui gui(m_Window);
	sf::Clock clock;
	Game::GameManager& GManager = Game::GameManager::Get();

	while (m_Window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		while (std::optional<sf::Event> evt = m_Window.pollEvent())
		{
			m_EventUpdateFunc(evt);
		}

		m_Window.clear();
		GManager.OnUpdate(deltaTime);
		Render();


		m_Window.display();
	}
}
void Window::Close()
{
	m_Window.close();
}

void CC::Window::Render()
{
	const std::vector<LayerSpecification>& layers = Game::GameManager::Get().GetCurrentScene()->GetSceneLayers();

	for(const auto& layer : layers)
	{
		for(const auto& drawable : layer.layer->GetDrawables())
		{
			m_Window.draw(*drawable);
		}
	}

}
