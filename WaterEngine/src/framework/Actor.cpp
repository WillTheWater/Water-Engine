#include "framework/Actor.h"
#include "framework/World.h"
#include "framework/Core.h"

namespace we
{
	Actor::Actor(World* owningWorld)
		: mOwningWorld{owningWorld}
		, mBeganPlay{false}
	{
	}
	Actor::~Actor()
	{
	}
	void Actor::BeginPlayInternal()
	{
		if (!mBeganPlay)
		{
			mBeganPlay = true;
			BeginPlay();
		}
	}
	void Actor::BeginPlay()
	{
		LOG("Actor Begin Play");
	}
	void Actor::Tick(float deltaTime)
	{
		LOG("Actor Tick");
	}
}