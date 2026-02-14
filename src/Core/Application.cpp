#include "PCH.hpp"
#include "Core/Application.hpp"
#include "Core/LayerManager.hpp"
#include "Core/Layer.hpp"
#include "Game/GameManager.hpp"

using namespace CC;

Application::Application(const ApplicationSpecification& specification)
{
	this->m_ApplicationSpecification = specification;

	m_application = this;
}

Application::~Application()
{

}

bool Application::Init()
{
	auto boundFunc = std::bind(&EventSystem::UpdateEvents, &EventSystem::Get(), std::placeholders::_1);
	m_Window = std::make_unique<Window>(m_ApplicationSpecification.windowSettings, std::function<void(const std::optional<sf::Event>&)>(boundFunc));
	CCLOG("Application Initialized Successfully!\n");
	
	EventHandleID closehandle;
	EventSystem::Get().Subscribe(EventType::WINDOW_CLOSE, closehandle, BIND_EVENT_FUNCTION(Application, CloseApp));

	Game::GameManager::Get().Init(m_ApplicationSpecification.ApplicationFlags);

	return true;
}
void Application::CloseApp(const sf::Event::Closed& evt)
{
	Game::GameManager::Get().OnDestroy();
	m_Window->Close();
}
void Application::Run()
{
	Game::GameManager::Get().OnStart();
	m_Window->Loop();
}
