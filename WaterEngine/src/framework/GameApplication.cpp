#include "framework/GameApplication.h"
#include "framework/Core.h"

namespace we
{
	GameApplication::GameApplication(unsigned int windowWidth, unsigned int windowHeight, const std::string& windowTitle, sf::Uint32 windowStyle)
		: mWindow{ sf::VideoMode(windowWidth, windowHeight), windowTitle, windowStyle }
		, mTargetFrameRate{ 60.f }
		, mClock{}
		, mCurrentWorld{ nullptr }
	{
	}
	void GameApplication::Run()
	{
		mClock.restart();
		float accumulatedTime{ 0.f };
		float targetDeltaTime{ 1.f / mTargetFrameRate };
		while (mWindow.isOpen())
		{
			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::Closed) { mWindow.close(); }
			}
			float frameDeltaTime = mClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime) 
			{ 
				accumulatedTime -= targetDeltaTime; 
				TickInternal(targetDeltaTime); 
				RenderInternal();
			}
		}
	}
	void GameApplication::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
		if (mCurrentWorld)
		{
			mCurrentWorld->TickInternal(deltaTime);
		}
	}
	void GameApplication::Tick(float deltaTime)
	{
	}
	void GameApplication::RenderInternal()
	{
		mWindow.clear();
		Render();
		mWindow.display();
	}
	void GameApplication::Render()
	{
	}
}