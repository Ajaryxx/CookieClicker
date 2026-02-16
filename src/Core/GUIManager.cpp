#include "PCH.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"
#include "Core/GUIBase.hpp"

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

	for (const auto& item : m_umapGuis)
	{
		item.second->UpdateEvents(event.value());
	}
}

void CC::GUIManager::RenderGUI()
{
	for(const auto& item : m_umapGuis)
	{
		item.second->Render();
	}
}

bool CC::GUIManager::GUIExists(const std::string& GUIName) const
{
	auto it = m_umapGuis.find(GUIName);
	if (it != m_umapGuis.end())
	{
		return true;
	}
	return false;
}
