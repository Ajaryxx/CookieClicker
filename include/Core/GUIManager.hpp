#pragma once
#include "Utilities.hpp"

namespace CC
{

	class GUIBase;

	class GUIManager
	{
	public:
		GUIManager(sf::RenderWindow& window);
		~GUIManager();
	
	public:
		
		void UpdateGUIEvents(const std::optional<sf::Event>& event);
		void RenderGUI();
		void LoadGUIFromFile(const std::string& filepath);
		tgui::Group::Ptr GetGroup(const std::string& GroupName) const { m_Gui.get<tgui::Group>(GroupName); }
		template<typename T>
		T::Ptr GetWidget(const std::string& WidgetName) const;
	private:

	private:
		tgui::Gui m_Gui;
	
	};

	template<typename T>
	inline T::Ptr GUIManager::GetWidget(const std::string& WidgetName) const
	{
		 return m_Gui.get<T>(WidgetName);
	}

}