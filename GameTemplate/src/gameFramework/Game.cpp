#include "gameFramework/Game.h"
#include "framework/World.h"
#include "framework/Actor.h"

we::GameApplication* GetGameApplication() { return new we::Game(); }

namespace we
{
	Game::Game()
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		mTestActor = newWorld.lock()->SpawnActor<Actor>();
		mCount = 0.f;
	}
	void Game::Tick(float deltaTime)
	{
		mCount += deltaTime;
		if (mCount > 2.f)
		{
			if (!mTestActor.expired())
			{
				mTestActor.lock()->Destroy();
			}
		}
	}
}