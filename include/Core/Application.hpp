#pragma once
#include "Core/GameValues.hpp"

class Window;

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
	Window* GetWindow() const { return m_Window.get(); }
private:

	inline static Application* app = nullptr;
	ApplicationSpecification m_specification;

	std::unique_ptr<Window> m_Window;

};