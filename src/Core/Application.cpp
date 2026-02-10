#include "PCH.hpp"
#include "Core/Application.hpp"

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
	
	EventSystem::Get().ListenEvent(Events::WINDOW_CLOSE, std::bind(&Application::CloseApp, this, std::placeholders::_1));
	EventSystem::Get().ListenEvent(Events::KEY_PRESSED, std::bind(&Application::TestKeyPress, this, std::placeholders::_1));

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

void Application::Run()
{
	m_Window->Loop();
}
