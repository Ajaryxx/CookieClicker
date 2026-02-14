#include "PCH.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"
#include "Core/Application.hpp"

CC::GUIManager::GUIManager(sf::RenderWindow& window)
{
	m_gui = std::make_unique<tgui::Gui>(window);
}

void CC::GUIManager::UpdateGUIEvents(const std::optional<sf::Event>& event)
{
	if(event.has_value())
		m_gui->handleEvent(event.value());
}
