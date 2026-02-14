#pragma once
#include "Utilities.hpp"

namespace CC
{
	class GUIManager
	{
	public:
		GUIManager(sf::RenderWindow& window);
		~GUIManager() = default;
	
	public:
		
		void UpdateGUIEvents(const std::optional<sf::Event>& event);
		

	private:
		

	private:
		std::unique_ptr<tgui::Gui> m_gui = nullptr;
	};
}