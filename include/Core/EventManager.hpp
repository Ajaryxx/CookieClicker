#pragma once

class EventManager
{
public:
	EventManager(tgui::Gui* const gui);
	~EventManager();

	template<typename EVT, typename FUNC>
	void BindEvent();


	void UpdateEvents();
private:

	tgui::Gui* m_Gui;

};
