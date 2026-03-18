#include "PCH.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"

CC::GUIManager::GUIManager(sf::RenderWindow& window)
{
	EventHandleID IDResized;
	m_gui.setTarget(window);

	CCLOG("GUI Manager Initialized Successfully!");
}

CC::GUIManager::~GUIManager()
{
	CCLOG("GUI Manager Destroyed Successfully!");
}

void CC::GUIManager::UpdateGUIEvents(const std::optional<sf::Event>& event)
{
	if (!event.has_value())
		return;

	m_gui.handleEvent(event.value());
}

void CC::GUIManager::RenderGUI()
{
	m_gui.draw();
}
tgui::Group::Ptr CC::GUIManager::PushGroup(const std::string& GroupName)
{
	auto it = m_umapGroups.find(GroupName);
	if (it != m_umapGroups.end())
	{
		CCASSERT(false, "GroupName already exists!");
		return nullptr;
	}
	
	auto group = tgui::Group::create();
	m_umapGroups[GroupName] = group;

	m_gui.add(group, GroupName);

	return group;
}
