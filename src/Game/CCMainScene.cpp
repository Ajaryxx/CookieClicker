#include "PCH.hpp"
#include "Game/CCMainScene.hpp"
#include "Core/Application.hpp"

CC::Game::CCMainScene::CCMainScene() : Scene("CCMainScene")
{
	m_guiManager = &CC::Application::Get().GetWindow().GetGUIManager();
	m_guiManager->PushGUI("Main", "C:\\Users\\joelf\\Documents\\CodingProjects\\CookieClicker\\resources\\GUI\\MainGUI.txt", true);
	tgui::Button::Ptr b = m_guiManager->GetWidgetOfGUI<tgui::Button>("Main", "BTN_Settings");
	b->onClick([]() {CCLOG("HELLOOOOO"); });
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
