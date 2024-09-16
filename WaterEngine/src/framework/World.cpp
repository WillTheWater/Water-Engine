#include "framework/World.h"
#include "framework/Core.h"

namespace we
{
	World::World(GameApplication* owingGameApp)
		: mOwningGameApp{owingGameApp}
		, mBeganPlay{false}
	{
	}
	World::~World()
	{
	}
	void World::BeginPlayInternal()
	{
		if (!mBeganPlay)
		{
			mBeganPlay = true;
			BeginPlay();
		}
	}
	void World::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	}
	void World::BeginPlay()
	{
		LOG("Begin Play Called");
	}
	void World::Tick(float deltaTime)
	{
		LOG("Framerate: %f", 1.f / deltaTime);
	}
}