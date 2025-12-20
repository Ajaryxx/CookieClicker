#include "PCH.hpp"
#include "Core/GUIManager.hpp"

GUIManager::GUIManager(sf::RenderWindow& window)
{
	m_Gui = std::make_shared<tgui::Gui>(window);
}

GUIManager::~GUIManager()
{
}