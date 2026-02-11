#include "PCH.hpp"
#include "Core/Window.hpp"
#include "Utility/Macros.hpp"

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

	ASSERT(EventUpdateFunc, "EVENT_UPDATE_FUNC HAS TO BE A VALID PTR");
	m_EventUpdateFunc = EventUpdateFunc;


}
Window::~Window()
{
}

void Window::Loop()
{
	tgui::Gui gui(m_Window);
	while (m_Window.isOpen())
	{
		while (std::optional<sf::Event> evt = m_Window.pollEvent())
		{
			m_EventUpdateFunc(evt);
		}

		

		m_Window.clear();

		m_Window.display();
	}
}
void Window::Close()
{
	m_Window.close();
}