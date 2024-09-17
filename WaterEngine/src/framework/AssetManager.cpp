#include "framework/AssetManager.h"

namespace we
{
	unique<AssetManager> AssetManager::mAssetManager{nullptr};

	AssetManager::AssetManager()
	{
	}

	AssetManager& AssetManager::GetAssetManager()
	{
		if (!mAssetManager)
		{
			mAssetManager = unique<AssetManager>{new AssetManager};
		}
		return *mAssetManager;
	}
	shared<sf::Texture> AssetManager::LoadTexture(const std::string& texturePath)
	{
		auto it = mLoadedTextureMap.find(texturePath);
		if (it != mLoadedTextureMap.end())
		{
			return it->second;
		}
		shared<sf::Texture> newTexture{ new sf::Texture };
		if (newTexture->loadFromFile(texturePath))
		{
			mLoadedTextureMap.insert({ texturePath, newTexture });
			return newTexture;
		}
		return shared<sf::Texture> {nullptr};
	}
	void AssetManager::CleanCycle()
	{
		for (auto it = mLoadedTextureMap.begin(); it != mLoadedTextureMap.end();)
		{
			if (it->second && it->second.use_count() == 1)
			{
				it = mLoadedTextureMap.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}