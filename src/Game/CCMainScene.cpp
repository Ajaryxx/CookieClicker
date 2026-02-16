#include "PCH.hpp"
#include "Game/CCMainScene.hpp"
#include "Core/Application.hpp"

CC::Game::CCMainScene::CCMainScene() : Scene("CCMainScene")
{
	m_guiManager = &CC::Application::Get().GetWindow().GetGUIManager();
	m_guiManager->LoadGUIFromFile("C:\\Users\\joelf\\Documents\\CodingProjects\\CookieClicker\\resources\\GUI\\MainGUI.txt");
	auto pic = m_guiManager->GetWidget<tgui::Button>("IMG_Settings");
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
