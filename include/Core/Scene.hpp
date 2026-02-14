#pragma once
#include "Core/LayerManager.hpp"

namespace CC
{
	class Scene : public LayerManager
	{
	public:
		Scene(const std::string& m_SceneName) : m_SceneName(m_SceneName) {}
		~Scene() = default;

		virtual void OnStart() = 0;
		virtual void OnUpdate(float deltaTime) = 0;
		virtual void OnDestroy() = 0;

	private:

		std::string m_SceneName;

	};
}