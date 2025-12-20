#pragma once
#include "Core/GameValues.hpp"

#include "Core/GUIManager.hpp"
#include "Core/EventManager.hpp"

class EventManager;
class GUIManager;



class Window
{
public:
	Window(const ApplicationSpecification& spec);
	~Window();


	void Loop();
	inline GUIManager* GetGUIManager() const { return m_GUIManager.get(); }

private:

	std::unique_ptr<sf::RenderWindow> m_Window = nullptr;
	std::unique_ptr<GUIManager> m_GUIManager = nullptr;
	std::unique_ptr<EventManager> m_EventManager = nullptr;
};