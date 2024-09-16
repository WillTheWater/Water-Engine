#include "EntryPoint.h"
#include "framework/GameApplication.h"

int main()
{
	we::GameApplication* game = GetGameApplication();
	game->Run();
	delete game;
}