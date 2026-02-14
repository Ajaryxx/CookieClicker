#pragma once
#include "Utilities.hpp"
#include "Core/Scene.hpp"

namespace CC
{
	namespace Game
	{
		class GameManager
		{
		public:
			
			~GameManager() = default;
			GameManager(const GameManager&) = delete;
			GameManager& operator=(const GameManager&) = delete;

		public:
			inline static GameManager& Get() 
			{ 
				static GameManager instance;
				return instance;
			}
			inline uint8 GetFlags() const { return m_flags; }
			inline const Scene* GetCurrentScene() const { return m_currentScene.get(); }

			void Init(uint8 flags);
			void OnStart();
			void OnUpdate(float deltaTime);
			void OnDestroy();

		private:
			GameManager() = default;
			uint8 m_flags = 0x00;
			std::unique_ptr<Scene> m_currentScene = nullptr;
		};

	}

}
