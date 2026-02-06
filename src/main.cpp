#include "PCH.hpp"
#include "Core/Application.hpp"
#include "Core/Window.hpp"



static ApplicationSpecification GetReleaseSpecification()
{
	ApplicationSpecification spec;
	spec.ApplicationFlags = ApplicationFlags::NONE;
	spec.windowSettings.title = "Cookie Clicker [RELEASE]";
	spec.windowSettings.WindowSize = sf::VideoMode::getDesktopMode();
	spec.windowSettings.state = sf::State::Fullscreen;
	spec.windowSettings.style = sf::Style::Default;
	return spec;
}

static bool RunApp(const ApplicationSpecification& spec)
{
	Application app(spec);
	const bool InitSuccsess = app.Init();

	if (InitSuccsess)
	{
		app.Get().Run();
	}

	return InitSuccsess;
}

#if (defined(_WIN32) && defined(__DEBUG)) || defined(__linux__)

//Windows(Debug) Linux(Debug, Release)
int main(int argc, char* argv[])
{
	
#ifdef __DEBUG
	//DEBUG
	ApplicationSpecification spec;
	spec.ApplicationFlags = ApplicationFlags::NONE;
	spec.windowSettings.title = "Cookie Clicker [DEBUG]";
	spec.windowSettings.WindowSize = sf::VideoMode(sf::Vector2u(800, 600));
	spec.windowSettings.state = sf::State::Windowed;
	spec.windowSettings.style = sf::Style::Default;

#else
	//RELEASE
	ApplicationSpecification spec = GetReleaseSpecification();

#endif
	bool InitSuccsess = RunApp(spec);


	return InitSuccsess ? EXIT_SUCCESS : EXIT_FAILURE;
}

//Windows
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//RELEASE
	bool InitSuccsess = RunApp(GetReleaseSpecification());

	return InitSuccsess ? EXIT_SUCCESS : EXIT_FAILURE;
}


#endif

