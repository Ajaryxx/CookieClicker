#pragma once
#include "Utilities.hpp"
#include "WidgetBuilders.hpp"

namespace CC
{

	struct WidgetWrapper
	{
		BaseLayout* Layout;
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
	
	private:
		tgui::Gui m_gui;
	
	};
}