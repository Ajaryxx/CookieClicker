#include "PCH.hpp"
#include "Game/GameManager.hpp"
#include "Game/CCMainScene.hpp"
#include "Core/GUIManager.hpp"

CC::Game::GameManager::GameManager(uint8 flags)
{
	this->m_flags = flags;
	m_currentScene = std::make_unique<CCMainScene>();
}
void CC::Game::GameManager::OnUpdate(float deltaTime)
{
	m_currentScene->OnUpdate(deltaTime);
}
