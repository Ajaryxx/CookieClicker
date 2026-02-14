#include "PCH.hpp"
#include "Game/GameManager.hpp"
#include "Game/CCMainScene.hpp"
#include "Core/GUIManager.hpp"

void CC::Game::GameManager::Init(uint8 flags)
{
	this->m_flags = flags;
	m_currentScene = std::make_unique<CCMainScene>();
}

void CC::Game::GameManager::OnStart()
{
	CCLOG("Game Started!\n");
	
	GUIManager::Get().OnStart();
	
	m_currentScene->OnStart();
	
}
void CC::Game::GameManager::OnUpdate(float deltaTime)
{
	GUIManager::Get().OnUpdate();
	m_currentScene->OnUpdate(deltaTime);
}
void CC::Game::GameManager::OnDestroy()
{
	CCLOG("Game Destroyed!\n");
	GUIManager::Get().OnDestroy();
	m_currentScene->OnDestroy();
}