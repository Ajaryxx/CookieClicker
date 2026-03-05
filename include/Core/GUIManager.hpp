#pragma once
#include "Utilities.hpp"
#include "WidgetBuilders.hpp"

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
		//Can return nullptr
		template<typename T>
		T::Ptr GetWidgetInGroup(const std::string& groupName, const std::string& WidgetName);
		//Adds an widget to the gui and returns it
		//NOTE: Can return nullptr
		template<typename T>
		T::Ptr AddWidgetToGroup(const std::string& groupName, const std::string& WidgetName = "");
		//build a layout for a widget
		template<typename T>
		void SetLayoutWidget(const std::string& groupName, const std::string& WidgetName, BaseLayout& builder);
		tgui::Group::Ptr AddGroup(const std::string& groupName);
	private:
		void ResizeWidgets(const sf::Event::Resized& evt);
		
		inline tgui::Group::Ptr GetGroup(const std::string& groupName) const { return m_gui.get<tgui::Group>(groupName); }
	private:
		tgui::Gui m_gui;
		
	};

	template<typename T>
	inline T::Ptr GUIManager::GetWidgetInGroup(const std::string& groupName, const std::string& WidgetName)
	{
		auto group = GetGroup(groupName);
		if (!group)
		{
			CCASSERT(false, "Group doesn't exists");
			return nullptr;
		}
		auto widget = group->get<T>(WidgetName);
		if (!widget)
		{
			CCASSERT(false, "Widget doesn't exists");
		}

		return widget;
	}

	template<typename T>
	inline T::Ptr GUIManager::AddWidgetToGroup(const std::string& groupName, const std::string& WidgetName)
	{
		auto group = GetGroup(groupName);
		if (!group || group->get<T>(WidgetName))
		{
			CCASSERT(false, "Group doesn't exists or Widget name already exists");
			return nullptr;
		}

		auto Widget = T::create();
		group->add(Widget, WidgetName);

		return Widget;

	}
	template<typename T>
	void GUIManager::SetLayoutWidget(const std::string& groupName, const std::string& WidgetName, BaseLayout& builder)
	{
		auto widget = GetWidgetInGroup<T>(groupName, WidgetName);
		if (!widget)
		{
			CCLOG("Coulnd't find widget");
			CCASSERT(false, "Coulnd't find widget in GUI");
			return;
		}
		builder.BuildLayout(widget);
	
	}
}