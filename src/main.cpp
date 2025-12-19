#include "PCH.hpp"
#include "Core/Application.hpp"

#if _WIN32
#include <Windows.h>
#endif // _WIN32



int main()
{
	ApplicationSpecification spec;
#ifdef GAME_DEBUG
	spec.title = "Cookie Clicker [DEBUG]";
	spec.WindowSize = sf::VideoMode(sf::Vector2u(800, 600));
	spec.style = sf::Style::Default;
	spec.contextSettings = sf::ContextSettings();
	spec.state = sf::State::Windowed;
#endif // GAME_DEBUG

#ifdef GAME_RELEASE
	spec.title = "Cookie Clicker [RELEASE]";
	spec.WindowSize = sf::VideoMode(sf::Vector2u(800, 600));
	spec.style = sf::Style::Default;
	spec.contextSettings = sf::ContextSettings();
	spec.state = sf::State::Windowed;
#endif // GAME_RELEASE


	Application app(spec);
	app.Run();


	return EXIT_SUCCESS;
}


#ifdef defined(_WIN32)

	#ifdef GAME_RELEASE

		int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
		{
			ApplicationSpecification spec;
			spec.title = "Cookie Clicker [RELEASE]";
			spec.WindowSize = sf::VideoMode(sf::Vector2u(800, 600));
			spec.style = sf::Style::Default;
			spec.contextSettings = sf::ContextSettings();
			spec.state = sf::State::Fullscreen;


			Application app(spec);
			app.Run();

			return EXIT_SUCCESS;
		}
	#endif // GAME_RELEASE

#endif // _WIN32