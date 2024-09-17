#include "gameFramework/Game.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "config.h"

we::GameApplication* GetGameApplication() { return new we::Game(); }

namespace we
{
	Game::Game()
		: GameApplication{ 1920,1080, "Game Template", sf::Style::Titlebar | sf::Style::Close }
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		mTestActor = newWorld.lock()->SpawnActor<Actor>();
		mTestActor.lock()->SetTexture( GetResourceDir() + "graphics/idle/Unarmed_Idle_full.png");
		mCount = 0.f;
	}
	void Game::Tick(float deltaTime)
	{
		mCount += deltaTime;
		if (mCount > 10.f)
		{
			if (!mTestActor.expired())
			{
				mTestActor.lock()->Destroy();
			}
		}
	}
}