#include "PCH.hpp"
#include "Core/GUIManager.hpp"
#include "Core/EventSystem.hpp"
#include "Core/Application.hpp"

void CC::GUIManager::InitGUIManager(sf::RenderWindow& window)
{
	m_gui = std::make_unique<tgui::Gui>(window);
}

void CC::GUIManager::OnStart()
{
	CCLOG("GUI Manager Started!\n");
}

void CC::GUIManager::OnUpdate()
{
	std::optional<sf::Event> evt = EventSystem::Get().GetEvent();
	if(evt.has_value())
		m_gui->handleEvent(evt.value());
	
}
void CC::GUIManager::OnDestroy()
{

}