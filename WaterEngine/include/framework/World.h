#pragma once

namespace we
{
	class GameApplication;
	class World
	{
	public:
		World(GameApplication* owingGameApp);
		virtual ~World();

		void							BeginPlayInternal();
		void							TickInternal(float deltaTime);

	private:
		void							BeginPlay();
		void							Tick(float deltaTime);
		GameApplication*				mOwningGameApp;
		bool							mBeganPlay;
	};
}