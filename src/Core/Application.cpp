#include "PCH.hpp"
#include "Core/Application.hpp"
#include "Core/EventSystem.hpp"
#include "Game/GameManager.hpp"

using namespace CC;

Application::Application(const ApplicationSpecification& specification) : m_GameManager(Game::GameManager(m_ApplicationSpecification.ApplicationFlags))
{
	this->m_ApplicationSpecification = specification;
	m_application = this;

	m_Window = std::make_unique<Window>(m_ApplicationSpecification.windowSettings);
	CCLOG("Application Initialized Successfully!\n");

	EventHandleID closehandle;
	EventSystem::Get().Subscribe(EventType::WINDOW_CLOSE, closehandle, BIND_EVENT_FUNCTION(Application, CloseApp));
}

Application::~Application()
{

}

void Application::CloseApp(const sf::Event::Closed& evt)
{
	m_Window->CloseWindow();
}
void Application::Run()
{
	const sf::RenderWindow& window = m_Window->GetRenderWindow();
	sf::Clock clock;

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		//Handle events
		m_Window->PollEvents();

		m_GameManager.OnUpdate(deltaTime);

		m_Window->Render(m_GameManager.GetCurrentScene()->GetSceneLayers());
	}
}
