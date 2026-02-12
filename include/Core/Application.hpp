#pragma once
#include "BaseValues.hpp"
#include "Utility/Macros.hpp"
#include "Core/Window.hpp"
#include "Core/EventSystem.hpp"

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

		bool Init();
		void Run();

	private:
		void CloseApp(const sf::Event::Closed& evt);
		void TestKeyPress(const sf::Event::KeyPressed& evt);
		void TestKeyPress2(const sf::Event::KeyPressed& evt);
		void CustomEvent();
		void CustomEvent2();

	private:
		inline static Application* m_application = nullptr;
		ApplicationSpecification m_ApplicationSpecification;

	private:
		std::unique_ptr<Window> m_Window;

	};
}

