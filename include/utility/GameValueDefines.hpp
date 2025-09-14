#pragma once
#include "PCH.hpp"

struct WindowParameters
{
	const char* title;
	int width;
	int height;
	SDL_WindowFlags windowFlags;
};