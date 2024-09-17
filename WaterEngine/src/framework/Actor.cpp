#include "framework/Actor.h"
#include "framework/World.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"

namespace we
{
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		: mOwningWorld{owningWorld}
		, mBeganPlay{false}
		, mTexture{}
		, mSprite{}
	{
		SetTexture(texturePath);
	}
	Actor::~Actor()
	{
		LOG("Actor Destroyed")
	}
	void Actor::BeginPlayInternal()
	{
		if (!mBeganPlay)
		{
			mBeganPlay = true;
			BeginPlay();
		}
	}
	void Actor::TickInternal(float deltaTime)
	{
		if (!IsPendingDestroy())
		{
			Tick(deltaTime);
		}
	}
	void Actor::BeginPlay()
	{
		LOG("Actor Begin Play")
	}
	void Actor::Tick(float deltaTime)
	{
		// LOG("Actor Tick")
	}
	void Actor::SetTexture(const std::string& texturePath)
	{
		
		mTexture = AssetManager::GetAssetManager().LoadTexture(texturePath);
		if (!mTexture) { return; }
		mSprite.setTexture(*mTexture);
		int textureWidth = mTexture->getSize().x;
		int textureHeight = mTexture->getSize().y;
		mSprite.setTextureRect(sf::IntRect(sf::Vector2i{}, sf::Vector2i{ textureWidth , textureHeight}));
	}
	void Actor::Render(sf::RenderWindow& window)
	{
		if (IsPendingDestroy()) { return; }
		window.draw(mSprite);
	}
}