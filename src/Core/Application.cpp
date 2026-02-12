#include "PCH.hpp"
#include "Core/Application.hpp"

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
	EventHandleID key1;
	EventHandleID key2;
	EventSystem::Get().Subscribe(EventType::WINDOW_CLOSE, closehandle, BIND_EVENT_FUNCTION(Application, CloseApp));
	EventSystem::Get().Subscribe(EventType::KEY_PRESSED, key1, BIND_EVENT_FUNCTION(Application, TestKeyPress));
	//EventSystem::Get().Subscribe(EventType::KEY_PRESSED, key1, BIND_EVENT_FUNCTION(Application, TestKeyPress2));
	
	EventHandleID notifyID;
	EventSystem::Get().CreateCustomEvent("TEST", notifyID);

	EventHandleID customCall;
	EventHandleID customCall2;
	EventSystem::Get().Subscribe("TEST", customCall, BIND_CUSTOM_EVENT_FUNCTION(Application, CustomEvent));
	EventSystem::Get().Subscribe("TEST", customCall2, BIND_CUSTOM_EVENT_FUNCTION(Application, CustomEvent2));

	EventSystem::Get().CustomNotify("TEST");
	EventSystem::Get().Unsubscribe(customCall);
	EventSystem::Get().CustomNotify("TEST");

	//EventSystem::Get().Unsubscribe(key1);
	//EventSystem::Get().Unsubscribe(key1);
	

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
void Application::CustomEvent()
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
