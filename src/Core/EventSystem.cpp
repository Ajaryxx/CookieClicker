#include "PCH.hpp"
#include "Core/EventSystem.hpp"


CC::EventSystem::EventSystem()
{

}

CC::EventSystem::~EventSystem()
{
}

void CC::EventSystem::UpdateEvents(const std::optional<sf::Event>& evt)
{
	m_Event = evt;
	Notify();
}
void CC::EventSystem::Notify()
{
	m_Event->visit(Visitor(m_umap_Mapping, m_umap_SFMLCommandDispatch));
}
void CC::EventSystem::Unsubscribe(EventHandleID& handle)
{
	bool IsValidMappingID = false;
	auto ItMapping = m_umap_Mapping.begin();
	std::vector<EventHandleID>::iterator MappingVecDelPos;

	for (; ItMapping != m_umap_Mapping.end(); ItMapping++)
	{
		auto& vec = ItMapping->second;
		for (auto ItHandleIDVec = vec.begin(); ItHandleIDVec != vec.end(); ItHandleIDVec++)
		{
			if (*ItHandleIDVec == handle)
			{
				IsValidMappingID = true;
				MappingVecDelPos = ItHandleIDVec;
				break;
			}
				
		}
		if (IsValidMappingID)
			break;
	}
	auto ItSFML = m_umap_SFMLCommandDispatch.find(handle);
	bool IsValidPos = ItSFML != m_umap_SFMLCommandDispatch.end();

	if (IsValidPos && IsValidMappingID)
	{
		ItMapping->second.erase(MappingVecDelPos);
		m_umap_SFMLCommandDispatch.erase(ItSFML);
		CCLOG("Event ID successfully deleted: {}", handle);
		handle = -1;
	}
}
bool CC::EventSystem::IsValidEventID(EventType evt, EventHandleID& handleID)
{
	auto it = m_umap_Mapping.find(evt);
	if (it != m_umap_Mapping.end())
	{
		for (const auto& item : it->second)
		{
			if (handleID == item)
				return false;
		}

	}

	return true;
}