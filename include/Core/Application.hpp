#pragma once
#include "Core/GameValues.hpp"

class GameWindow;

class Application
{
public:
	Application(const ApplicationSpecification& specification);
	Application(const Application&) = delete;
	~Application();

	Application& operator=(const Application& other) = delete;

	inline Application& Get() { return *app; }

	void Run();
	void ShutDown();
	GameWindow& GetWindow() const { return *m_Window; }
private:

	inline static Application* app = nullptr;
	ApplicationSpecification m_specification;

	std::unique_ptr<GameWindow> m_Window;

};