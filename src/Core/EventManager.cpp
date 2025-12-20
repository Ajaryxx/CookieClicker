#include "PCH.hpp"
#include "Core/EventManager.hpp"

EventManager::EventManager()
{
	
}
EventManager::~EventManager()
{

}
void EventManager::UpdateEvents(tgui::Gui& gui)
{
	gui.handleWindowEvents();
}
