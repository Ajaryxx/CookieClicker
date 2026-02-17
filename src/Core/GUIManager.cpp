#include "PCH.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"

CC::GUIManager::GUIManager(sf::RenderWindow& window) : m_window(window)
{

	EventHandleID IDResized;
	EventSystem::Get().Subscribe(EventType::WINDOW_RESIZED, IDResized, BIND_EVENT_FUNCTION(GUIManager, ResizeWidgets));

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
void CC::GUIManager::PushGUI(const std::string& GUIName, bool active)
{
	if (GUINameExits(GUIName))
	{
		CCASSERT(false, "GUI name already exits");
		return;
	}
	
	m_umap_GUIS[GUIName] = GUIWrapper{ std::make_unique<tgui::Gui>(m_window), active };
}

bool CC::GUIManager::GUINameExits(const std::string& GUIName) const
{
	auto AIt = m_umap_GUIS.find(GUIName);
	return  AIt != m_umap_GUIS.end();;
}

void CC::GUIManager::ResizeWidgets(const sf::Event::Resized& evt)
{
	
}
