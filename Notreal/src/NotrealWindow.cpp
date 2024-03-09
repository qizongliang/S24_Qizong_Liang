#include "pch.h"
#include "NotrealWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace Notreal
{
	NotrealWindow::NotrealWindow()
	{
#ifdef NOTREAL_GLFW_WINDOW
		mWindow = std::unique_ptr<WindowImpl>{ new WindowGLFW };
#else
	#DEFINITION_NOTREAL_GLFW_is_missing
#endif

	}

	void NotrealWindow::Init()
	{
		if (!mInstance)
			mInstance = new NotrealWindow;
	}

	NotrealWindow* NotrealWindow::GetWindow()
	{
		return mInstance;
	}

	void NotrealWindow::Shutdown()
	{
		if (mInstance)
			delete mInstance;
	}

	void NotrealWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void NotrealWindow::PollEvents()
	{
		mWindow->PollEvents();
	}

	void NotrealWindow::Create(int width, int height)
	{
		mWindow->Create(width, height);

	}
	int NotrealWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}
	int NotrealWindow::GetHeight() const
	{
		return mWindow->GetHeight();
	}
}