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
		void							TickInternal(float deltaTime);
		virtual void					BeginPlay();
		virtual void					Tick(float deltaTime);
		void							SetTexture(const std::string& texturePath);
		void							Render(sf::RenderWindow& window);
		void							SetActorPosition(const sf::Vector2f position);
		void							SetActorRotation(float rotation);
		void							AddActorOffset(const sf::Vector2f& offset);
		void							SetActorRotationOffset(float rotation);
		sf::Vector2f					GetActorPosition() const;
		float							GetActorRotation() const;
		sf::Vector2f					GetActorForwardVector() const;
		sf::Vector2f					GetActorRightVector() const;
		void							SetTextureRect(int left, int top, int width, int height);
		void							ScaleActor(float scaleX, float scaleY);

	private:
		void							CenterActorOrigin();
		World*							mOwningWorld;
		bool							mBeganPlay;
		shared<sf::Texture>				mTexture;
		sf::Sprite						mSprite;
	};
}