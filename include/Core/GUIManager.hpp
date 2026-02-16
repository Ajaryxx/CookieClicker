#pragma once
#include "Utilities.hpp"
#include "Core/GUIBase.hpp"

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
		template<typename T>
		void PushGUI(const std::string& GUIName, bool visible = false, bool focused = false);

	private:
		bool GUIExists(const std::string& GUIName) const;

	private:
		sf::RenderWindow& m_window;

		std::unordered_map<std::string, std::unique_ptr<GUIBase>> m_umapNotVisible;
		std::unordered_map<std::string, std::unique_ptr<GUIBase>> m_umapGuis;
	};
	template<typename T>
	inline void GUIManager::PushGUI(const std::string& GUIName, bool visible, bool focused)
	{
		if (!GUIExists(GUIName))
		{
			if(visible)
			{
				m_umapGuis[GUIName] = std::make_unique<T>(m_window);
				m_umapGuis[GUIName]->Start();
			}
			else
			{
				m_umapNotVisible[GUIName] = std::make_unique<T>(m_window);
				m_umapNotVisible[GUIName]->Start();
			}
			
		}
		else
		{
			assert(false && "GUI with the same name already exists!");
		}
	}
}