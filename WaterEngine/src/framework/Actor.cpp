#include "framework/Actor.h"
#include "framework/World.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"

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
	}
	void Actor::SetTexture(const std::string& texturePath)
	{
		
		mTexture = AssetManager::GetAssetManager().LoadTexture(texturePath);
		if (!mTexture) { return; }
		mSprite.setTexture(*mTexture);
		int textureWidth = mTexture->getSize().x;
		int textureHeight = mTexture->getSize().y;
		mSprite.setTextureRect(sf::IntRect(sf::Vector2i{}, sf::Vector2i{ textureWidth , textureHeight}));
		CenterActorOrigin();
	}
	void Actor::Render(sf::RenderWindow& window)
	{
		if (IsPendingDestroy()) { return; }
		window.draw(mSprite);
	}
	void Actor::SetActorPosition(const sf::Vector2f position)
	{
		mSprite.setPosition(position);
	}
	void Actor::SetActorRotation(float rotation)
	{
		mSprite.setRotation(rotation);
	}
	void Actor::AddActorOffset(const sf::Vector2f& offset)
	{
		SetActorPosition(GetActorPosition() + offset);
	}
	void Actor::SetActorRotationOffset(float rotation)
	{
		SetActorRotation(GetActorRotation() + rotation);
	}
	sf::Vector2f Actor::GetActorPosition() const
	{
		return mSprite.getPosition();;
	}
	float Actor::GetActorRotation() const
	{
		return mSprite.getRotation();
	}
	sf::Vector2f Actor::GetActorForwardVector() const
	{
		return RotationToVector(GetActorRotation());
	}
	sf::Vector2f Actor::GetActorRightVector() const
	{
		return RotationToVector(GetActorRotation() + 90.f);
	}
	void Actor::SetTextureRect(int left, int top, int width, int height)
	{
		mSprite.setTextureRect(sf::IntRect(left, top, width, height));
	}
	void Actor::ScaleActor(float scaleX, float scaleY)
	{
		mSprite.setScale(scaleX, scaleY);
	}
	void Actor::CenterActorOrigin()
	{
		sf::FloatRect bounds = mSprite.getGlobalBounds();
		mSprite.setOrigin(bounds.getSize().x / 2.f, bounds.getSize().y / 2.f);
	}
}