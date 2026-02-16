#include "PCH.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"

CC::GUIManager::GUIManager(sf::RenderWindow& window)
{
	CCLOG("GUI Manager Initialized Successfully!");
	m_Gui.setTarget(window);
}

CC::GUIManager::~GUIManager()
{
	CCLOG("GUI Manager Destroyed Successfully!");
}

void CC::GUIManager::UpdateGUIEvents(const std::optional<sf::Event>& event)
{
	if (!event.has_value())
		return;

	m_Gui.handleEvent(event.value());
}

void CC::GUIManager::RenderGUI()
{
	m_Gui.draw();
}
void CC::GUIManager::LoadGUIFromFile(const std::string& filepath)
{
	m_Gui.loadWidgetsFromFile(filepath);
}