#include "PCH.hpp"
#include "Game/CCMainScene.hpp"
#include "Core/Application.hpp"
#include "Core/ResourceManager.hpp"

CC::Game::CCMainScene::CCMainScene() : Scene("CCMainScene")
{
	m_guiManager = &CC::Application::Get().GetWindow().GetGUIManager();
	BuildGUIs();
	
}

void CC::Game::CCMainScene::Start()
{
	
}

void CC::Game::CCMainScene::Update(float deltaTime)
{
	
}

void CC::Game::CCMainScene::Destroy()
{

}

void CC::Game::CCMainScene::BuildGUIs()
{
	BuildMainGUI();
}

void CC::Game::CCMainScene::BuildMainGUI()
{
	m_guiManager->PushGUI("MainCCGUI", true);

	auto SettingsBtn = m_guiManager->AddWidgetToGUI<tgui::Button>("MainCCGUI", "BTN");
	SettingsBtn->getRenderer()->setTexture(*ResourceManager::Get().GetResource<sf::Texture>(MakePath({"Textures", "MissingTexture.png"})));
	

}
