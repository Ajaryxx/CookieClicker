#pragma once
#include "Utilities.hpp"
#include "WidgetBuilders.hpp"

namespace CC
{

	struct WidgetWrapper
	{
		std::unique_ptr<WidgetBuilder> Builder;
		tgui::Widget::Ptr Widget;
	};

	class GUIManager
	{
	public:
		GUIManager(sf::RenderWindow& window);
		~GUIManager();
	
	public:
		
		void UpdateGUIEvents(const std::optional<sf::Event>& event);
		void RenderGUI();
	
		tgui::Group::Ptr PushGroup(const std::string& GroupName);

		template<typename WIDGET, typename BUILDER>
		WIDGET::Ptr AddWidgetToGroup(const std::string& GroupName, const std::string& WidgetName, const BUILDER& builder);

		std::unordered_map<std::string, tgui::Group::Ptr> m_umapGroups;
		std::unordered_map<std::string, WidgetWrapper> m_umapWidgets;

	private:
		tgui::Gui m_gui;
	
	};

	template<typename WIDGET, typename BUILDER>
	inline WIDGET::Ptr GUIManager::AddWidgetToGroup(const std::string& GroupName, const std::string& WidgetName, const BUILDER& builder)
	{
		auto widget = m_umapWidgets.find(WidgetName);
		auto Group = m_umapGroups.find(GroupName);

		if (Group == m_umapGroups.end() || widget != m_umapWidgets.end())
		{
			CCASSERT(false, "Group name doesn't exists or widget name already exists");
			return nullptr;
		}
		
		auto newWidget = WIDGET::create();

		m_umapWidgets[WidgetName] = WidgetWrapper{ std::make_unique<BUILDER>(builder), newWidget };;

		Group->second->add(newWidget, WidgetName);

		//should be safe to call this function
		m_umapWidgets.find(WidgetName)->second.Builder->CheckAndBuildLayout(newWidget);


		return newWidget;
	}
}