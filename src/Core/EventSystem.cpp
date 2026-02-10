#include "PCH.hpp"
#include "Core/EventSystem.hpp"

EventSystem::EventSystem()
{

}

EventSystem::~EventSystem()
{
}

void EventSystem::UpdateEvents(const std::optional<sf::Event>& evt)
{
	m_Event = evt;
	Notify();
}
void EventSystem::Notify()
{
	m_Event->visit(Visitor(m_umap_SFMLCommandDispatch));
}