#include "PCH.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"
#include "Core/Application.hpp"

CC::GUIManager::GUIManager(sf::RenderWindow& window) : m_window(window)
{
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

	for (const auto& item : m_umapHuis)
	{
		item.second->handleEvent(event.value());
	}
}

void CC::GUIManager::RenderGUI()
{
	for(const auto& item : m_umapHuis)
	{
		item.second->draw();
	}
}

void CC::GUIManager::PushGUI(const std::string& GUIName)
{
	if(!GUIExists(GUIName))
	{
		m_umapHuis[GUIName] = std::make_unique<tgui::Gui>(m_window);
	}

}

bool CC::GUIManager::GUIExists(const std::string& GUIName) const
{
	auto it = m_umapHuis.find(GUIName);
	if (it != m_umapHuis.end())
	{
		return true;
	}
	return false;
}
