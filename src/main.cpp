#include <iostream>
#include "core/Application.hpp"


int main()
{
	WindowParameters windowInfo{};
	windowInfo.title = "Cookie Clicker";
	windowInfo.width = 800;
	windowInfo.height = 600;
	windowInfo.windowFlags = SDL_WINDOW_OPENGL;

	Application app(windowInfo);
	if (!app.Init())
		return EXIT_FAILURE;
	else
		app.Run();
	
	return EXIT_SUCCESS;
}