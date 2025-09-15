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

struct Color
{
	constexpr Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {};
	constexpr Color(float rgb) : r(rgb), g(rgb), b(rgb), a(1.f) {};
	float r;
	float g;
	float b;
	float a;

	static const Color RED;
	static const Color GREEN;
	static const Color BLUE;

};
inline constexpr Color Color::RED = Color(1.f, 0.f, 0.f, 1.f);
inline constexpr Color Color::GREEN = Color(0.f, 1.f, 0.f, 1.f);
inline constexpr Color Color::BLUE = Color(0.f, 0.f, 1.f, 1.f);


struct Vertex2D
{
	glm::vec2 position;
	glm::vec2 texCoords;
	Color color;
};