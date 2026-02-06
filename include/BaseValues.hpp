#pragma once
#include <cstdint>

typedef uint8_t uint8;
typedef uint8_t int8;

typedef uint16_t uint16;
typedef uint16_t int16;

typedef uint32_t uint32;
typedef uint32_t int32;

typedef uint64_t uint64;
typedef uint64_t int64;


struct WindowParameters
{
	sf::String title;
	sf::VideoMode WindowSize;
	uint8 style;
	sf::State state;
	sf::ContextSettings ContextSettings{};

};

enum ApplicationFlags : uint8
{
	NONE = 1 << 0,
};

struct ApplicationSpecification
{
	uint8 ApplicationFlags = 0x00;
	WindowParameters windowSettings;
};
