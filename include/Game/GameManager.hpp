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

		//Can return nullptr if no GUI is set
		template<typename T>
		T* GetGUI() const { return m_guiManager.get(); }
		//Sets a new GUI, the old one will be overwritten
		template<typename T>
		void SetGUI();
	private:
			
		uint8 m_flags = 0x00;
		std::unique_ptr<Scene> m_currentScene = nullptr;
		CC::Application* m_app = nullptr;
		std::unique_ptr<GUIManager> m_guiManager = nullptr;

	};


	template<typename T>
	inline void Game::GameManager::SetGUI()
	{
		m_guiManager = std::make_unique<T>(m_app->GetWindow());
	}

}
