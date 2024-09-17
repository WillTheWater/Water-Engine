#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace we
{
	// This is a singleton
	class AssetManager
	{
	public:
		static AssetManager&				   GetAssetManager();
		shared<sf::Texture>					   LoadTexture(const std::string& texturePath);
	protected:
		AssetManager();

	private:
		static unique<AssetManager>			   mAssetManager;
		Umap<std::string, shared<sf::Texture>> mLoadedTextureMap;
	};
}