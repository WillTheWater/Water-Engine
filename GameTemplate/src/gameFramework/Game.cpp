#include "gameFramework/Game.h"
#include "framework/World.h"

we::GameApplication* GetGameApplication() { return new we::Game(); }

namespace we
{
	Game::Game()
	{
		LoadWorld<World>();
	}
}