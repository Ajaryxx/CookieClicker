#pragma once
#include "PCH.hpp"

typedef int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int64_t int64;
typedef uint64_t uint64;

struct WindowParameters
{
	const char* title;
	int32 width;
	int32 height;
	SDL_WindowFlags windowFlags;
};