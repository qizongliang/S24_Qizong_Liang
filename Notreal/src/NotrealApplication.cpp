#include "pch.h"

#include "NotrealWindow.h"
#include "NotrealApplication.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Image.h"
#include "Shader.h"
#include "NotrealKeys.h"

namespace Notreal 
{
	NotrealApplication::NotrealApplication()
	{
		NotrealWindow::Init();
		NotrealWindow::GetWindow()->Create(1000, 800);

		Renderer::Init();

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
		
	}
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

		//NotrealWindow::Init();
		//NotrealWindow::GetWindow()->Create(1000, 800);

		//Renderer::Init();

		///////// Sharders ///////

		//Shader sProg{"C:\\Users\\qizon\\Desktop\\gameengine\\S24_Qizong_Liang\\Notreal\\Assets\\Shaders\\DefaultVertexShader.glsl","C:\\Users\\qizon\\Desktop\\gameengine\\S24_Qizong_Liang\\Notreal\\Assets\\Shaders\\DefaultFragmentShader.glsl" };

		////////// Texture /////////

		//Notreal::Image pic{"..Assets\\test.png"};
		//Notreal::Image picbg{ "..Assets\\hamburger.png" };
		
	
		Initialize();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		//int x{ 0 };
		//int y{ 0 };

		//SetKeyPressedCallback([&x, &y](const KeyPressed& event){
		//	if (event.GetKeyCode() == NOTREAL_KEY_RIGHT)
		//		x += 50;
		//	if (event.GetKeyCode() == NOTREAL_KEY_LEFT)
		//		x -= 50;
		//	if (event.GetKeyCode() == NOTREAL_KEY_UP)
		//		y += 50;
		//	if (event.GetKeyCode() == NOTREAL_KEY_DOWN)
		//		y -= 50;
		//});


		while (mShouldContinue)
		{
			Renderer::ClearScreen();

			OnUpdate();
			//Renderer::Draw(picbg, 100, 00);
            //Renderer::Draw(pic, x, y);

			
			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			NotrealWindow::GetWindow()->SwapBuffers();
			NotrealWindow::GetWindow()->PollEvents();
		}

		Shutdown();

		NotrealWindow::Shutdown();
	}

	void NotrealApplication::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) 
	{
		NotrealWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}
	void NotrealApplication::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		NotrealWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}
	void NotrealApplication::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		NotrealWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}
	void NotrealApplication::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}
}