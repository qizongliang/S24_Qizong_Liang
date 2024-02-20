#include "pch.h"

#include"NotrealApplication.h"

namespace Notreal 
{
	void NotrealApplication::Initialize()
	{

	}
	void NotrealApplication::OnUpdate()
	{

	}
	void NotrealApplication::Shutdown()
	{

	}
	void NotrealApplication::Run()
	{
		Initialize();

		while (true) 
		{
			OnUpdate();

		}

		Shutdown();
	}
}