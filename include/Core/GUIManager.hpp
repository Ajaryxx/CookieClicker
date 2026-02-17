#pragma once
#include "Utilities.hpp"

namespace CC
{

	struct GUIWrapper
	{
		std::unique_ptr<tgui::Gui> gui;
		bool active;
	};

	
	class GUIManager
	{
	public:
		GUIManager(sf::RenderWindow& window);
		~GUIManager();
	
	public:
		
		void UpdateGUIEvents(const std::optional<sf::Event>& event);
		void RenderGUI();
		void PushGUI(const std::string& GUIName, const std::string& path, bool active = false);
		//Can return nullptr
		template<typename T>
		T::Ptr GetWidgetOfGUI(const std::string& GUIName, const std::string& WidgetName);
	private:
		bool GUINameExits(const std::string& GUIName) const;


	private:
		sf::RenderWindow& m_window;
		tgui::Gui m_Gui;
	
		std::unordered_map<std::string, GUIWrapper> m_umap_GUIS;
		
	
	};


	template<typename T>
	inline T::Ptr GUIManager::GetWidgetOfGUI(const std::string& GUIName, const std::string& WidgetName)
	{
		if (!GUINameExits(GUIName))
		{
			CCASSERT(false, "GUI doesnt exits");
			return nullptr;
		}
		return m_umap_GUIS.find(GUIName)->second.gui->get<T>(WidgetName);
		
	}

}