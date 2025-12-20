#pragma once

class GUIManager
{
public:
	GUIManager(sf::RenderWindow& window);
	~GUIManager();

	std::shared_ptr<tgui::Gui> GetGUI() const { return m_Gui; }

private:
	std::shared_ptr<tgui::Gui> m_Gui = nullptr;
};