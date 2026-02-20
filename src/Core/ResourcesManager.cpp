#include "PCH.hpp"
#include "Core/ResourceManager.hpp"
#include "Core/Application.hpp"

CC::ResourceManager::ResourceManager()
{
	Application& app = Application::Get();

	m_ResourcePath = fs::current_path() / fs::path("resources");
	if (!fs::exists(m_ResourcePath))
	{
#ifdef _WIN32
		MESSAGE_BOX(app.GetWindow().GetRenderWindow().getNativeHandle(), "The resource path doesn't exists. Make sure you didn't delete or moved the resource directory.", "ERROR", MB_OK | MB_ICONERROR);
#endif // _WIN32
		CCLOG("The resource path doesn't exists. Make sure you didn't delete or moved the resource directory.");
		return;
	}

	auto MissingTexture = GetResource<sf::Texture>(MissingTextureRelPath);
	if (!MissingTexture)
	{
#ifdef _WIN32
		MESSAGE_BOX(app.GetWindow().GetRenderWindow().getNativeHandle(), "A crucial Texture couldn't be found. Make sure you didn't delete \"MissingTexture.png\"", "TEXTURE_ERROR", MB_OK | MB_ICONERROR);
#endif // _WIN32
		CCLOG("A crucial Texture couldn't be found. Make sure you didn't delete \"MissingTexture.png\"");
		return;
	}
	InitSuccess = true;

	tgui::Texture::setDefaultSmooth(false);

}