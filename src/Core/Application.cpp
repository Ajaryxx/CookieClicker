#include "PCH.hpp"
#include "Core/Application.hpp"
#include "Core/LayerManager.hpp"
#include "Core/Layer.hpp"

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

	LayerManager manager;
	manager.PushLayer("Layer1", 6);
	manager.PushLayer("Layer2", 5);
	//manager.EraseLayer("Layer2");
	
	return true;
}
void Application::CloseApp(const sf::Event::Closed& evt)
{
	m_Window->Close();
}
void Application::TestKeyPress(const sf::Event::KeyPressed& evt)
{
	if (evt.code == sf::Keyboard::Key::Enter)
		CCLOG("ENTER PRESSED");
}
void Application::TestKeyPress2(const sf::Event::KeyPressed& evt)
{
	if (evt.code == sf::Keyboard::Key::Enter)
		CCLOG("ENTER PRESSED 2");
}
void Application::CustomEvent0()
{
	CCLOG("CUSTOM EVENT");
}
void Application::CustomEvent2()
{
	CCLOG("CUSTOM EVENT2");
}
void Application::Run()
{
	m_Window->Loop();
}
