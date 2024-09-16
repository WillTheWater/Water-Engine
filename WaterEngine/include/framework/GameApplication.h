#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/World.h"

namespace we
{
	class World;
	class GameApplication
	{
	public:
		GameApplication();

		void						Run();

		template<typename WorldType>
		weak<WorldType> LoadWorld();

	private:
		void						TickInternal(float deltaTime);
		virtual void				Tick(float deltaTime);
		void						RenderInternal();
		virtual void				Render();
		sf::RenderWindow			mWindow;
		float						mTargetFrameRate;
		sf::Clock					mClock;
		shared<World>				mCurrentWorld;
	};
	template<typename WorldType>
	inline weak<WorldType> GameApplication::LoadWorld()
	{
		shared<WorldType> newWorld{ new WorldType{this} };
		mCurrentWorld = newWorld;
		mCurrentWorld->BeginPlayInternal();
		return newWorld;
	}
}
