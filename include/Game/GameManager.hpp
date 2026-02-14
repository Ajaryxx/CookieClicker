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
			GameManager(uint8 flags = 0x00);
			~GameManager() = default;
			GameManager(const GameManager&) = delete;
			GameManager& operator=(const GameManager&) = delete;

			
		public:
			inline uint8 GetFlags() const { return m_flags; }
			inline const Scene* GetCurrentScene() const { return m_currentScene.get(); }

			void OnUpdate(float deltaTime);

		private:
			
			uint8 m_flags = 0x00;
			std::unique_ptr<Scene> m_currentScene = nullptr;
		};

	}

}
