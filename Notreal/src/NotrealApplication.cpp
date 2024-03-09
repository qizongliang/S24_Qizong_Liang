#include "pch.h"
#include "NotrealWindow.h"
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
		NotrealWindow::Init();
		NotrealWindow::GetWindow()->Create(1000, 800);

		Initialize();

		while (true) 
		{
			OnUpdate();

			NotrealWindow::GetWindow()->SwapBuffers();
			NotrealWindow::GetWindow()->PollEvents();
		}

		Shutdown();
		NotrealWindow::Shutdown();
	}
}