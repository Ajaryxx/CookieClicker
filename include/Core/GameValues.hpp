#pragma once
#include <cstdint>
#include <SFML/Window.hpp>

typedef uint8_t uint8;
typedef int8_t int8;

typedef uint16_t uint16;
typedef int16_t int16;

typedef uint32_t uint32;
typedef int32_t int32;

typedef uint64_t uint64;
typedef int64_t int64;

struct ApplicationSpecification
{
	sf::String title;
	sf::VideoMode WindowSize;
	sf::State state;
	sf::ContextSettings contextSettings;
	uint8 style;

};