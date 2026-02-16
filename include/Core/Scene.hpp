#pragma once
#include "Core/LayerManager.hpp"

namespace CC
{
	class Scene : public LayerManager
	{
	public:
		Scene(const std::string& m_SceneName) : m_SceneName(m_SceneName) {}
		virtual ~Scene() = default;

		virtual void Start() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Destroy() = 0;

	private:

		std::string m_SceneName;

	};
}