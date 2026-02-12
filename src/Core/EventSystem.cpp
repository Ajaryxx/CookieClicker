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
	m_Event->visit(Visitor(m_umap_Mapping, m_umap_EventDispatch));
}
void CC::EventSystem::CustomNotify(const std::string& customEventName)
{
	auto it = m_umap_Mapping.find(customEventName);

	if (it != m_umap_Mapping.end())
	{
		for (const auto& item : it->second)
		{
			auto ItEvtDisp = m_umap_EventDispatch.find(item);
			if (ItEvtDisp != m_umap_EventDispatch.end())
			{
				if (auto func = std::get_if<EvtCustomEvent>(&ItEvtDisp->second))
				{
					(*func)();
				}
			}
		}
	}
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
	auto ItSFML = m_umap_EventDispatch.find(handle);
	bool IsValidPos = ItSFML != m_umap_EventDispatch.end();

	if (IsValidPos && IsValidMappingID)
	{
		ItMapping->second.erase(MappingVecDelPos);
		m_umap_EventDispatch.erase(ItSFML);
		CCLOG("Event ID successfully deleted: {}", handle);
		handle = -1;
	}
	else
		CCLOG("Event ID was invalid. Handle: {}", handle);
}
bool CC::EventSystem::IsValidEventID(EventHandleID& handleID) const
{
	for (auto it = m_umap_Mapping.cbegin(); it != m_umap_Mapping.cend(); it++)
	{	
		for (const auto& item : it->second)
		{
			if (item == handleID)
				return false;
		}
	}

	return true;
}
CC::EventHandleID CC::EventSystem::GenerateValidHandlerID() const
{
	EventHandleID handleID = 0;
	do { handleID = Utility::GenRandomInt32(0, INT32_MAX); } while (!IsValidEventID(handleID));

	return handleID;
}
bool CC::EventSystem::IsCustomEventNameValid(const std::string& name) const
{
	auto it = m_umap_Mapping.find(name);
	return it != m_umap_Mapping.end();
}
void CC::EventSystem::CreateCustomEvent(const std::string& eventName, EventHandleID& handleID)
{
	auto it = m_umap_Mapping.find(eventName);

	if (it != m_umap_Mapping.end())
	{
		CCLOG("Custom event already exits! Event Name: {}", eventName);
		return;
	}
	handleID = GenerateValidHandlerID();

	
	m_umap_Mapping[eventName];

	CCLOG("Custom event created with name: {}", eventName);
}