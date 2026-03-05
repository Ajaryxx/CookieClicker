#include "PCH.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"

CC::GUIManager::GUIManager(sf::RenderWindow& window)
{
	EventHandleID IDResized;
	EventSystem::Get().Subscribe(EventType::WINDOW_RESIZED, IDResized, BIND_EVENT_FUNCTION(GUIManager, ResizeWidgets));
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
tgui::Group::Ptr CC::GUIManager::AddGroup(const std::string& groupName)
{
	if (GetGroup(groupName))
	{
		CCASSERT(false, "Group name already exists");
		return nullptr;
	}
	auto group = tgui::Group::create();
	m_gui.add(group, groupName);

	return group;

}
void CC::GUIManager::ResizeWidgets(const sf::Event::Resized& evt)
{
	for (const auto& item : m_gui.getWidgets())
	{
		CCLOG("Widget name: {}", item->getWidgetName().toStdString());
		
	}
}
