#include "framework/Actor.h"
#include "framework/World.h"
#include "framework/Core.h"

namespace we
{
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		: mOwningWorld{owningWorld}
		, mBeganPlay{false}
		, mTexture{}
		, mSprite{}
	{

	}
	Actor::~Actor()
	{
		LOG("Actor Destroyed")
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
		LOG("Actor Begin Play")
	}
	void Actor::Tick(float deltaTime)
	{
		// LOG("Actor Tick")
	}
}