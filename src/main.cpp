#include "PCH.hpp"
#include "Core/Application.hpp"

#if _WIN32
#include <Windows.h>
#endif // _WIN32

#if (defined(_WIN32) && GAME_DEBUG) || defined(__linux__)

int main()
{
	sf::ContextSettings contSettings;
	contSettings.attributeFlags |= sf::ContextSettings::Default;

	ApplicationSpecification spec;
#ifdef GAME_DEBUG
	spec.title = "Cookie Clicker [DEBUG]";
	spec.WindowSize = sf::VideoMode(sf::Vector2u(800, 600));
	spec.style = sf::Style::Default;
	spec.contextSettings = contSettings;
	spec.state = sf::State::Windowed;
#endif // GAME_DEBUG

#ifdef GAME_RELEASE
	spec.title = "Cookie Clicker [RELEASE]";
	spec.WindowSize = sf::VideoMode::getDesktopMode();
	spec.style = sf::Style::Default;
	spec.contextSettings = contSettings;
	spec.state = sf::State::Fullscreen;
#endif // GAME_RELEASE


	Application app(spec);
	app.Run();


	return EXIT_SUCCESS;
}
#endif // defined(_WIN32) && GAME_DEBUG || defined(__linux__)

#if (defined(_WIN32) && GAME_RELEASE)

	int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
	{
		sf::ContextSettings contSettings;
		contSettings.attributeFlags |= sf::ContextSettings::Default;

		ApplicationSpecification spec;
		spec.title = "Cookie Clicker [RELEASE]";
		spec.WindowSize = sf::VideoMode::getDesktopMode();
		spec.style = sf::Style::Default;
		spec.contextSettings = contSettings;
		spec.state = sf::State::Fullscreen;


		Application app(spec);
		app.Run();

		return EXIT_SUCCESS;
	}

#endif // _WIN32