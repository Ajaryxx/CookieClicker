#pragma once
#include "Utilities.hpp"

namespace CC
{
	class GUIManager
	{
	public:
		~GUIManager() = default;
		GUIManager(const GUIManager&) = delete;
		GUIManager& operator=(const GUIManager&) = delete;
	public:
		inline static GUIManager& Get() 
		{ 
			static GUIManager instance;
			return instance;
		}

		void InitGUIManager(sf::RenderWindow& window);
		void OnStart();
		void OnUpdate();
		void OnDestroy();

	private:
		GUIManager() = default;

	private:
		std::unique_ptr<tgui::Gui> m_gui = nullptr;
	};
}