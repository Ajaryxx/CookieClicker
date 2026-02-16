#pragma once
#include "Utilities.hpp"
#include "Core/Window.hpp"

namespace CC::Game { class GameManager; }

namespace CC
{
	class Application
	{
	public:
		Application(const ApplicationSpecification& specification);
		~Application();

		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;


	public:
		inline static Application& Get() { return *m_application; }
		inline Game::GameManager& GetGameManager() { return *m_GameManager.get(); }
		inline Window& GetWindow() const { return *m_Window; }

		void Run();

	private:
		void CloseApp(const sf::Event::Closed& evt);

	private:
		inline static Application* m_application = nullptr;
		ApplicationSpecification m_ApplicationSpecification;

	private:
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<Game::GameManager> m_GameManager;

	};
}

