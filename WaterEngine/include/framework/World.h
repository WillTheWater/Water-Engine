#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace we
{
	class Actor;
	class GameApplication;
	class World
	{
	public:
		World(GameApplication* owingGameApp);
		virtual ~World();

		void							BeginPlayInternal();
		void							TickInternal(float deltaTime);
		void							Render(sf::RenderWindow& window);

		template<typename ActorType>
		weak<ActorType> SpawnActor();

	private:
		void							BeginPlay();
		void							Tick(float deltaTime);
		GameApplication*				mOwningGameApp;
		bool							mBeganPlay;
		list<shared<Actor>>				mActors; // Vector of Actor objects
		list<shared<Actor>>				mPendingActors; //Vector of Actors to be added 
	};
	template<typename ActorType>
	inline weak<ActorType> World::SpawnActor()
	{
		shared<ActorType> newActor{ new ActorType{this} };
		mPendingActors.push_back(newActor);
		return newActor;
	}
}