#include "framework/Object.h"
#include "framework/Core.h"

namespace we
{
	Object::Object()
		: mIsPendingDestroy{false}
	{
	}
	Object::~Object()
	{
		LOG("Object Destroyed")
	}
	void Object::Destroy()
	{
		mIsPendingDestroy = true;
	}
}