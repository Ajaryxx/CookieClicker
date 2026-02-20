#pragma once
#include "Utilities.hpp"

namespace fs = std::filesystem;

using Resources = std::variant<
std::shared_ptr<sf::SoundBuffer>,
std::shared_ptr<sf::Texture>,
std::shared_ptr<sf::Font>>;

namespace CC
{
	class ResourceManager
	{
	public:
		~ResourceManager() = default;

		static ResourceManager& Get()
		{
			static ResourceManager manager;
			return manager;
		}

		std::unordered_map<std::string, Resources> m_umap_Resources;

		template<typename T>
		std::shared_ptr<T> GetResource(const std::string& ResourceName);

		inline bool IsInitSuccess() const { return InitSuccess; }
	private:
		ResourceManager();
		fs::path m_ResourcePath;

		template<typename T>
		std::shared_ptr<T> ResourceExits(const std::string& ResourceName) const;

		template<typename T>
		std::shared_ptr<T> LoadResourceFromFile(const std::string& relativePath);

		const std::string MissingTextureRelPath = "Textures/MissingTexture.png";
		bool InitSuccess = false;

	};
	template<typename T>
	inline std::shared_ptr<T> ResourceManager::GetResource(const std::string& ResourceName)
	{
		auto ExistsRes = ResourceExits<T>(ResourceName);
		if (ExistsRes)
		{
			CCLOG("Resource: {} already exists. Returning needed resource", ResourceName);
			return ExistsRes;
		}
			
		auto LoadedRes = LoadResourceFromFile<T>(ResourceName);
		if (LoadedRes)
		{
			CCLOG("Resource: {} loaded. Returning needed resource", ResourceName);
			return LoadedRes;
		}

		CCLOG("Couldn't find texture, lets return the missing texture.");
		//if its a texure and we cannot find it, we return missing texture instead
		auto& VariantTex = m_umap_Resources.find(MissingTextureRelPath)->second;
		if (std::holds_alternative<std::shared_ptr<sf::Texture>>(VariantTex))
		{
			if (auto MissingTex = std::get_if<std::shared_ptr<sf::Texture>>(&VariantTex))
			{
				return *MissingTex;
			}
		}
		return nullptr;
	}

	template<typename T>
	inline std::shared_ptr<T> ResourceManager::ResourceExits(const std::string& ResourceName) const
	{
		//Find resource in umap
		auto it = m_umap_Resources.find(ResourceName);
		if (it != m_umap_Resources.end())
		{
			//return as weak_ptr
			if (auto res = std::get_if<std::shared_ptr<T>>(&it->second))
				return *res;
		}

		return nullptr;
		
	}

	template<typename T>
	inline std::shared_ptr<T> ResourceManager::LoadResourceFromFile(const std::string& relativePath)
	{
		const fs::path path = m_ResourcePath / relativePath;

		//return as weak_ptr
		auto ExistsRes = ResourceExits<T>(relativePath);
		if (ExistsRes)
			return ExistsRes;

		if (!fs::exists(path))
		{
			CCLOG("Resource doesnt exits. Path: {}", path.string());
			return nullptr;
		}
		
		//add to umap
		m_umap_Resources[relativePath] = std::make_shared<T>(path);
		auto it = m_umap_Resources.find(relativePath);

		//return as weak_ptr
		if (auto res = std::get_if<std::shared_ptr<T>>(&it->second))
			return *res;
		else
			return nullptr;

	}
}
