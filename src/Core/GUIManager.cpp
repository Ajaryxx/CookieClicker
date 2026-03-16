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
