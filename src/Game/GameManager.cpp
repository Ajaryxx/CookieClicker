#include "PCH.hpp"
#include "Game/GameManager.hpp"
#include "Game/CCMainScene.hpp"
#include "Core/GUIManager.hpp"
#include "Core/Application.hpp"


CC::Game::GameManager::GameManager(CC::Application* app, uint8 flags)
{
	this->m_app = app;
	this->m_flags = flags;
	CCLOG("Game Manager Initialized Successfully!\n");
}

CC::Game::GameManager::~GameManager()
{
	CCLOG("Game Manager Destroyed Successfully!");
}

void CC::Game::GameManager::Start()
{
	m_currentScene = std::make_unique<CCMainScene>();
	m_currentScene->Start();
}
void CC::Game::GameManager::Update(float deltaTime)
{
	m_currentScene->Update(deltaTime);
}
void CC::Game::GameManager::Destroy()
{
	m_currentScene->Destroy();
}
