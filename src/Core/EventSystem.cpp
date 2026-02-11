#include "PCH.hpp"
#include "Core/EventSystem.hpp"

using namespace CC;

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
	m_Event->visit(Visitor(m_mapping, m_umap_SFMLCommandDispatch));
}
void EventSystem::Unsubscribe(EventHandleID& handle)
{
	//TODO: Fix this

	for (auto ItMapping = m_mapping.begin(); ItMapping != m_mapping.end(); ItMapping++)
	{
		bool found = false;
		for (const auto& item : ItMapping->second)
		{
			if (item == handle)
			{
				found = true;
				break;
			}
				
		}
		if (found)
			break;
	}
	auto ItSFML = m_umap_SFMLCommandDispatch.find(handle);

	if (ItSFML != m_umap_SFMLCommandDispatch.end())
	{
		m_umap_SFMLCommandDispatch.erase(ItSFML);
	}

	handle = -1;
}
bool CC::EventSystem::ValidHandle(EventType evt, EventHandleID& handleID)
{
	auto it = m_mapping.find(evt);
	if (it != m_mapping.end())
	{
		for (const auto& item : it->second)
		{
			if (handleID == item)
				return false;
		}

	}

	return true;
}