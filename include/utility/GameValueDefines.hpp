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
	static const Color WHITE;

};
inline constexpr Color Color::RED = Color(1.f, 0.f, 0.f, 1.f);
inline constexpr Color Color::GREEN = Color(0.f, 1.f, 0.f, 1.f);
inline constexpr Color Color::BLUE = Color(0.f, 0.f, 1.f, 1.f);
inline constexpr Color Color::WHITE = Color(1.f);


struct Vertex2D
{
	constexpr Vertex2D() : position(glm::vec2(0.f)), texCoords(glm::vec2(0.f)), color(Color::WHITE) {};
	constexpr Vertex2D(const glm::vec2& position, const glm::vec2& texCoords, const Color& color) : position(position), texCoords(texCoords), color(color) {};

	glm::vec2 position;
	glm::vec2 texCoords;
	Color color;
};

struct VertexBuffer2DInfo
{
	uint8 numVertecies;
	const Vertex2D* vertexData;
	GLenum usage;
};

enum SeverityFilter : int8
{
	NONE = -1,
	NOTIFICATION = 0x00,
	LOW = 0x01,
	MEDIUM = 0x02,
	HIGH = 0x04,
	ALL = NOTIFICATION | LOW | MEDIUM | HIGH,
};

struct Transformation2D
{
	glm::vec2 position;
	float rotation;
	glm::vec2 scale;
};



inline constexpr Vertex2D TriangleVertexData[3] = {

	Vertex2D{glm::vec2(-1.f, -1.f),
			glm::vec2(0.f, 0.f),
			Color::WHITE},

	Vertex2D{glm::vec2(0.f, 1.f),
			glm::vec2(0.f, 1.f),
			Color::WHITE},

	Vertex2D{glm::vec2(1.f, -1.f),
			glm::vec2(1.f, 0.f),
			Color::WHITE},
};

inline constexpr Vertex2D RectangleVertexData[4] = {

	Vertex2D{glm::vec2(-1.f, -1.f),
			glm::vec2(0.f, 0.f),
			Color::WHITE},

	Vertex2D{glm::vec2(-1.f, 1.f),
			glm::vec2(0.f, 1.f),
			Color::WHITE},

	Vertex2D{glm::vec2(1.f, -1.f),
			glm::vec2(1.f, 0.f),
			Color::WHITE},

	Vertex2D{glm::vec2(1.f, 1.f),
			glm::vec2(1.f, 1.f),
			Color::WHITE},
};