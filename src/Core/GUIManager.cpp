#include "PCH.hpp"
#include "Core/GUIManager.hpp"

GUIManager::GUIManager(sf::RenderWindow& window)
{
	m_Gui = std::make_unique<tgui::Gui>(window);
}

GUIManager::~GUIManager()
{
}