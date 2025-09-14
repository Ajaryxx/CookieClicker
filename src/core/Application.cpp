#include "PCH.hpp"
#include "core/Application.hpp"
#include "core/Window.hpp"

Application::Application(const WindowParameters& windowParameter)
{
	m_AppWindow = std::make_unique<Window>(windowParameter);
}

Application::~Application()
{

}
bool Application::Init()
{
	const bool succses = m_AppWindow->Init();
	return succses;
}
void Application::Run()
{
	m_AppWindow->Loop();
}
