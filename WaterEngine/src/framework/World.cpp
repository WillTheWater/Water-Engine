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
		// ================================================
		//         Double Buffer for Actor spawning 
		// ================================================
		for (shared<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->BeginPlayInternal();
		}
		mPendingActors.clear();
		// ================================================
		//        Iterates mActor for Actors to destroy 
		// ================================================
		for (auto it = mActors.begin(); it != mActors.end();)
		{
			if (it->get()->IsPendingDestroy()) { it = mActors.erase(it); }
			else { it->get()->TickInternal(deltaTime); ++it; }
		}
		
		Tick(deltaTime);
	}
	void World::Render(sf::RenderWindow& window)
	{
		for (auto& actor : mActors)
		{
			actor->Render(window);
		}
	}
	void World::BeginPlay()
	{
		LOG("Begin Play Called")
	}
	void World::Tick(float deltaTime)
	{
		// LOG("Framerate: %f", 1.f / deltaTime)
	}
}