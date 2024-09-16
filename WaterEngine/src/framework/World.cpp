#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace we
{
	World::World(GameApplication* owingGameApp)
		: mOwningGameApp{owingGameApp}
		, mBeganPlay{false}
		, mActors{}
		, mPendingActors{}
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
		for (shared<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->BeginPlayInternal();
		}
		mPendingActors.clear();
		for (shared<Actor> actor : mActors)
		{
			actor->Tick(deltaTime);
		}
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