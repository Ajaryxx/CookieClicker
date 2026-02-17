#include "PCH.hpp"
#include "Core/ResourceManager.hpp"

CC::ResourceManager::ResourceManager()
{
	m_ResourcePath = fs::current_path() / fs::path("resources");
	if(!fs::exists(m_ResourcePath))
		ShowMBox(nullptr, "The resource path doesnt exists", "ERROR", MB_OK | MB_ICONERROR);


	GetResource<sf::Texture>("Textures\\MissingTexture.png");
	GetResource<sf::Texture>("Textures\\MissingTexture.png");
}