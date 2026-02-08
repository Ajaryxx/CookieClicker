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
	m_Window = std::make_unique<Window>(m_ApplicationSpecification.windowSettings);
	CCLOG("Application Initialized Successfully!\n");
	

	return true;
}
void Application::Run()
{
	m_Window->Loop();
}
