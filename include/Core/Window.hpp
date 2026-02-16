#pragma once
#include "Utilities.hpp"
#include "Core/GUIManager.hpp"
#include "Core/LayerManager.hpp"

namespace CC
{

	class Window
	{
	public:
		Window(const WindowParameters& specification);
		~Window();
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		inline GUIManager& GetGUIManager() { return *m_GUIManager; }
		inline const sf::RenderWindow& GetRenderWindow() const { return m_Window; }
		inline bool IsOpen() const { return m_Window.isOpen(); }

		void PollEvents();
		void CloseWindow();
		void Render(const std::vector<LayerSpecification>& layers);
	private:
		

		sf::RenderWindow m_Window;
		WindowParameters m_Specification;
		std::function<void(const std::optional<sf::Event>&)> m_EventUpdateFunc;
		std::unique_ptr<GUIManager> m_GUIManager = nullptr;
	};
}

