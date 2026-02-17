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
		void PushGUI(const std::string& GUIName, bool active = false);
		//Can return nullptr
		template<typename T>
		T::Ptr GetWidgetOfGUI(const std::string& GUIName, const std::string& WidgetName);
		//Adds an widget to the gui and returns it
		//NOTE: Can return nullptr
		template<typename T>
		T::Ptr AddWidgetToGUI(const std::string& GUIName, const std::string& WidgetName = "");
	private:
		bool GUINameExits(const std::string& GUIName) const;
		void ResizeWidgets(const sf::Event::Resized& evt);

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

	template<typename T>
	inline T::Ptr GUIManager::AddWidgetToGUI(const std::string& GUIName, const std::string& WidgetName)
	{
		if (!GUINameExits(GUIName))
		{
			CCASSERT(false, "GUI doesnt exits");
			return nullptr;
		}

		auto& it = m_umap_GUIS.find(GUIName)->second.gui;
		auto Widget = T::create(WidgetName);
	
		it->add(Widget, WidgetName);

		return GetWidgetOfGUI<T>(GUIName, WidgetName);

	}

}