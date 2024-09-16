#pragma once

namespace we
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		void							Destroy();
		bool							IsPendingDestroy() const { return mIsPendingDestroy; }

	private:
		bool							mIsPendingDestroy;
	};
}