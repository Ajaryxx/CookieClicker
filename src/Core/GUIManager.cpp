#include "PCH.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"

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

	for (const auto& item : m_umap_GUIS)
	{
		if (item.second.active)
			item.second.gui->handleEvent(event.value());
	}

}

void CC::GUIManager::RenderGUI()
{
	for (const auto& item : m_umap_GUIS)
	{
		if(item.second.active)
			item.second.gui->draw();
	}
}
void CC::GUIManager::PushGUI(const std::string& GUIName, const std::string& path, bool active)
{
	CCASSERT(std::filesystem::exists(path), "File doesnt exits");
	if (GUINameExits(GUIName))
	{
		CCASSERT(false, "GUI name already exits");
		return;
	}
	
	m_umap_GUIS[GUIName] = GUIWrapper{ std::make_unique<tgui::Gui>(m_window), active };
	m_umap_GUIS.find(GUIName)->second.gui->loadWidgetsFromFile(path);

}

bool CC::GUIManager::GUINameExits(const std::string& GUIName) const
{
	auto AIt = m_umap_GUIS.find(GUIName);
	return  AIt != m_umap_GUIS.end();;
}
