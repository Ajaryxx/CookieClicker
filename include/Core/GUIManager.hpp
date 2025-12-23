#pragma once

class GUIManager
{
public:
	GUIManager(sf::RenderWindow& window);
	~GUIManager();

	tgui::Gui& GetGUI() const { return *m_Gui; }

private:
	std::unique_ptr<tgui::Gui> m_Gui = nullptr;
};