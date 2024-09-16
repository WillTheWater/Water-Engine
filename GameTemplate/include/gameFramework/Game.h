#pragma once
#include <framework/GameApplication.h>
#include <framework/Core.h>

namespace we
{
	class Actor;
	class Game : public GameApplication
	{
	public:
		Game();

		virtual void					Tick(float deltaTime) override;

	private:
		float							mCount;
		weak<Actor>						mTestActor;
	};
}