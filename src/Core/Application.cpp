#include "PCH.hpp"
#include "Core/Application.hpp"
#include "Core/Window.hpp"

Application::Application(const ApplicationSpecification& specification)
{
	app = this;
	m_specification = specification;
	m_Window = std::make_unique<Window>(m_specification);
}

Application::~Application()
{

}
void Application::Run()
{
	m_Window->Loop();
}
void Application::ShutDown()
{

}