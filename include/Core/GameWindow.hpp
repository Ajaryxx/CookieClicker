#pragma once
#include "Core/GameValues.hpp"

#include "Core/GUIManager.hpp"
#include "Core/EventManager.hpp"


class GameWindow
{
public:
	GameWindow(const ApplicationSpecification& spec);
	~GameWindow();


	void Loop();
	inline GUIManager& GetGUIManager() const { return *m_GUIManager; }

private:

	std::unique_ptr<sf::RenderWindow> m_Window = nullptr;
	std::unique_ptr<GUIManager> m_GUIManager = nullptr;
	std::unique_ptr<EventManager> m_EventManager = nullptr;
};