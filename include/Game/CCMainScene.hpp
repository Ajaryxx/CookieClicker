#pragma once
#include "Core/Scene.hpp"

namespace CC { class GUIManager; }

namespace CC::Game
{

	class CCMainScene : public Scene
	{
	public:
		CCMainScene();
		~CCMainScene() = default;

	private:

		// Inherited via Scene
		void Start() override;
		void Update(float deltaTime) override;
		void Destroy() override;


		void BuildGUIs();
		void BuildMainGUI();

	private:
		GUIManager* m_guiManager = nullptr;
	};

}