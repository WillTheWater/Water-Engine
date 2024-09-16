#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/Object.h"

namespace we
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");
		virtual ~Actor();

		void							BeginPlayInternal();
		virtual void					BeginPlay();
		virtual void					Tick(float deltaTime);

	private:
		World*							mOwningWorld;
		bool							mBeganPlay;
		sf::Texture						mTexture;
		sf::Sprite						mSprite;
	};
}