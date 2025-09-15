#pragma once
#include "utility/GameValueDefines.hpp"

class Texture
{
public:
	Texture(const std::filesystem::path& texturePath);
	~Texture();


	void bind();
	void unbind();

	void LoadTexture(const std::filesystem::path& texturePath);
private:
	int32 m_width;
	int32 m_height;
	int32 m_bpp;

	GLuint m_textureID;

};