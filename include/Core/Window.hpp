#pragma once
#include "Utilities.hpp"

namespace CC
{
	class Window
	{
	public:
		Window(const WindowParameters& specification, std::function<void(const std::optional<sf::Event>&)> EventUpdateFunc);
		~Window();
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		void Loop();
		void Close();
	private:
		void Render();

		sf::RenderWindow m_Window;
		WindowParameters m_Specification;
		std::function<void(const std::optional<sf::Event>&)> m_EventUpdateFunc;
	};
}

