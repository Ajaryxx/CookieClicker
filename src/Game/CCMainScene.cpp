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

	m_guiManager->AddGroup("TEST")->setSize(10, 10);
	auto btn1 = m_guiManager->AddWidgetToGroup<tgui::Button>("TEST", "BTN1");
	
	//btn1->setPosition(tgui::Layout2d("50%", "50%"));
	ButtonLayout layout;
	layout.text = "Hello";
	layout.size = tgui::Layout2d(50.f, 50.f);

	m_guiManager->SetLayoutWidget<tgui::Button>("TEST", "BTN1", layout);

}
