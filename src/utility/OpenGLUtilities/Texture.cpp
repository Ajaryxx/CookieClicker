#include "PCH.hpp"
#include "utility/OpenGLUtilities/Texture.hpp"
#include "stb_image.h"

namespace fs = std::filesystem;

Texture::Texture(const fs::path& texturePath)
{
	LoadTexture(texturePath);
}
Texture::~Texture()
{
	glDeleteTextures(1, &m_textureID);
}
void Texture::LoadTexture(const fs::path& texturePath)
{
	if (!fs::exists(texturePath))
	{
		spdlog::info("Couldnt find texture path: {}", texturePath.u8string());
		return;
	}

	stbi_uc* image = stbi_load(texturePath.string().c_str(), &m_width, &m_height, &m_bpp, STBI_rgb_alpha);
	if (!image)
	{
		spdlog::error("Couldnt load image");
		return;
	}

	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	unbind();

	if (image)
		stbi_image_free(image);
	
}
void Texture::bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
}
void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}