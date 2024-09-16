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
	}
}