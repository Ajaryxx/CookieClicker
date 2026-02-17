#pragma once
#include "Utilities.hpp"
#include "Core/Scene.hpp"
#include "Core/GUIManager.hpp"
#include "Core/Application.hpp"

namespace CC::Game
{
	class GameManager
	{
	public:
		GameManager(CC::Application* app, uint8 flags = 0x00);
		~GameManager();
		GameManager(const GameManager&) = delete;
		GameManager& operator=(const GameManager&) = delete;

	public:
		inline uint8 GetFlags() const { return m_flags; }
		inline const Scene* GetCurrentScene() const { return m_currentScene.get(); }
		void Start();
		void Update(float deltaTime);
		void Destroy();

	private:
			
		uint8 m_flags = 0x00;
		std::unique_ptr<Scene> m_currentScene = nullptr;
		CC::Application* m_app = nullptr;

	};

}
