#pragma once
#include "Utilities.hpp"

namespace CC
{
	class GUIManager
	{
	public:
		GUIManager(sf::RenderWindow& window);
		~GUIManager();
	
	public:
		
		void UpdateGUIEvents(const std::optional<sf::Event>& event);
		void RenderGUI();
		void PushGUI(const std::string& GUIName);
		//inline tgui::Group::Ptr GetGroup(const std::string& name) const { return m_gui->get<tgui::Group>(name); }
	private:
		bool GUIExists(const std::string& GUIName) const;

	private:
		sf::RenderWindow& m_window;

		std::unordered_map<std::string, std::unique_ptr<tgui::Gui>> m_umapHuis;
	};
}