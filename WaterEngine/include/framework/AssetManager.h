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
		void								   CleanCycle();
	protected:
		AssetManager();

	private:
		static unique<AssetManager>			   mAssetManager;
		std::unordered_map<std::string, std::shared_ptr<sf::Texture>> mLoadedTextureMap;
	};
}