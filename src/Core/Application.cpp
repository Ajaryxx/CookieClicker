#include "PCH.hpp"
#include "Core/Application.hpp"
#include "Core/EventSystem.hpp"
#include "Game/GameManager.hpp"
#include "Core/ResourceManager.hpp"

CC::Application::Application(const ApplicationSpecification& specification)
{
	this->m_ApplicationSpecification = specification;
	m_application = this;

	m_Window = std::make_unique<Window>(m_ApplicationSpecification.windowSettings);

	EventHandleID closehandle;
	EventSystem::Get().Subscribe(EventType::WINDOW_CLOSE, closehandle, BIND_EVENT_FUNCTION(Application, CloseApp));

	IsAppOk = ResourceManager::Get().IsInitSuccess();

	if (!IsAppOk)
	{
		m_Window->CloseWindow();
		return;
	}

	m_GameManager = std::make_unique<Game::GameManager>(this, m_ApplicationSpecification.ApplicationFlags);

	CCLOG("Application Initialized Successfully!\n");
}

CC::Application::~Application()
{
	CCLOG("Application Destroyed Successfully!");
}

void CC::Application::CloseApp(const sf::Event::Closed& evt)
{
	m_GameManager->Destroy();
	m_Window->CloseWindow();
}
bool CC::Application::Run()
{
	if (!IsAppOk)
		return false;

	m_GameManager->Start();

	sf::Clock clock;

	while (m_Window->IsOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		//Window is handling all the events
		m_Window->PollEvents();

		//updating the game
		m_GameManager->Update(deltaTime);

		//rendering the game
		m_Window->Render(m_GameManager->GetCurrentScene()->GetSceneLayers());
	}

	return IsAppOk;
}
