#pragma once
#include "BaseValues.hpp"
#include "Utility/HelperMacros.hpp"
#include "Core/Window.hpp"

class Application
{
public:
	Application(const ApplicationSpecification& specification);
	~Application();

	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;


	inline static Application& Get() { return *m_application; }

	bool Init();
	void Run();

private:

	inline static Application* m_application = nullptr;
	ApplicationSpecification m_ApplicationSpecification;

private:
	std::unique_ptr<Window> m_Window;

};