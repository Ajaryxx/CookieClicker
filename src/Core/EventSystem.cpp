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
	if(m_Event.has_value())
		m_Event->visit(Visitor(m_umap_Mapping, m_umap_EventDispatch));
}
void CC::EventSystem::CustomNotify(const std::string& evtName)
{
	auto it = m_umap_Mapping.find(evtName);

	if (it != m_umap_Mapping.end())
	{
		for (const auto& item : it->second)
		{
			//call every function in EvtDisp that is bound to that ID
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
void CC::EventSystem::Unsubscribe(EventHandleID& handleID)
{
	bool IsValidMappingID = false;
	auto ItMapping = m_umap_Mapping.begin();
	std::vector<EventHandleID>::iterator MappingVecDelPos;

	//search for EventHandleID
	for (; ItMapping != m_umap_Mapping.end(); ItMapping++)
	{
		//search for handlerID in mapping vec
		auto& vec = ItMapping->second;
		for (auto ItHandleIDVec = vec.begin(); ItHandleIDVec != vec.end(); ItHandleIDVec++)
		{
			if (*ItHandleIDVec == handleID)
			{
				IsValidMappingID = true;
				//get pos of handlerID
				MappingVecDelPos = ItHandleIDVec;
				break;
			}
				
		}
		if (IsValidMappingID)
			break;
	}
	auto ItSFML = m_umap_EventDispatch.find(handleID);
	bool IsValidPos = ItSFML != m_umap_EventDispatch.end();
	if (IsValidPos && IsValidMappingID)
	{
		ItMapping->second.erase(MappingVecDelPos);
		m_umap_EventDispatch.erase(ItSFML);
		CCLOG("Event ID successfully deleted: {}", handleID);
		handleID = -1;
	}
	else
		CCLOG("Couldn't delete Event handle ID. ID was invalid. Handle: {}", handleID);
}
bool CC::EventSystem::IsValidEventID(EventHandleID handleID) const
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
bool CC::EventSystem::CreateCustomEvent(const std::string& eventName)
{
	if (IsCustomEventNameValid(eventName))
	{
		CCLOG("Custom event already exits! Event Name: {}", eventName);
		return false;
	}
	//We only want to define the new custom event. Handlers will be bound to that custom event
	m_umap_Mapping[eventName];

	CCLOG("Custom event created with name: {}", eventName);

	return true;

}
bool CC::EventSystem::DeleteCustomEvent(const std::string& evtName)
{
	auto it = m_umap_Mapping.find(evtName);

	if (it != m_umap_Mapping.end())
	{
		//Mapping vec
		for (auto handleID = it->second.begin(); handleID != it->second.end();)
		{
			auto ItDisp = m_umap_EventDispatch.find(*handleID);

			if (ItDisp != m_umap_EventDispatch.end())
			{
				handleID = it->second.erase(handleID);
				m_umap_EventDispatch.erase(ItDisp);
			}
			else
				handleID++;
			
		}
		m_umap_Mapping.erase(it);
	}
	else
	{
		CCLOG("Couldn't find event with name: {}. No event was deleted!", evtName);
		return false;
	}

	CCLOG("Custom event with name: {} successfully deleted!", evtName);
	return true;
}