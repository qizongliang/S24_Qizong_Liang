#pragma once

#include "Utility.h"

namespace Notreal 
{
	class NOTREAL_API NotrealApplication
	{
	public:
		virtual void Initialize();
		virtual void OnUpdate();
		virtual void Shutdown();

		void Run();

	private:

	};
}