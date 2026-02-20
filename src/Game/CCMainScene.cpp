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
	ResourceManager& RManager = ResourceManager::Get();

	m_guiManager->PushGUI("MainCCGUI", true);
	auto SettingsBtn = m_guiManager->AddWidgetToGUI<tgui::Button>("MainCCGUI", "BTN_Settings");
	//auto SettingsBtn2 = m_guiManager->AddWidgetToGUI<tgui::Button>("MainCCGUI", "BTN_Settings2");

	//button layout
	ButtonLayout layout{};
	layout.text = "";
	layout.size = tgui::Layout2d("20%", "25%");
	layout.position = tgui::Layout2d("100% - &.size.width", "0%");
	
	layout.UnfocusedTexture = *RManager.GetResource<sf::Texture>("Widgets/UI_UnfocusedGear.png");
	layout.HoverTexture = *RManager.GetResource<sf::Texture>("Widgets/UI_FocusedGear.png");

	
	m_guiManager->SetLayoutWidget<tgui::Button>("MainCCGUI", "BTN_Settings", layout);
	//m_guiManager->SetLayoutWidget<tgui::Button>("MainCCGUI", "BTN_Settings2", layout2);
}
