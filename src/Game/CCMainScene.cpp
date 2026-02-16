#include "PCH.hpp"
#include "Game/CCMainScene.hpp"
#include "Core/Application.hpp"
#include "Game/CCMainGUI.hpp"

CC::Game::CCMainScene::CCMainScene() : Scene("CCMainScene")
{
	m_guiManager = &CC::Application::Get().GetWindow().GetGUIManager();
	m_guiManager->PushGUI<CCMainGUI>("MainGameGUI");
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
