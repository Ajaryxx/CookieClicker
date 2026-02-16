#pragma once
#include "Utilities.hpp"

namespace CC
{
	class GUIBase
	{
	public:
		GUIBase(sf::RenderWindow& window) : m_GUI(window) { };
		virtual ~GUIBase();

		inline void UpdateEvents(const std::optional<sf::Event>& event) { m_GUI.handleEvent(event.value()); }
		inline void Render() { m_GUI.draw(); }
		virtual void Start() = 0;
		virtual void Destroy() = 0;

	protected:
		void LoadGUIFromFile(const std::string& filePath);
		tgui::Group::Ptr GetGroup(const std::string& name) const { return m_GUI.get<tgui::Group>(name); }

	private:

		tgui::Gui m_GUI;

	};
}
