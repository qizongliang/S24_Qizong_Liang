#include "pch.h"

#include "NotrealWindow.h"
#include "NotrealApplication.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include "Image.h"
#include "Shader.h"
#include"Renderer.h"

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
		Renderer::Init();

		NotrealWindow::Init();
		NotrealWindow::GetWindow()->Create(1000, 800);

		///////// Sharders ///////

		Shader sProg{"C:\\Users\\qizon\\Desktop\\gameengine\\S24_Qizong_Liang\\Notreal\\Assets\\Shaders\\DefaultVertexShader.glsl","C:\\Users\\qizon\\Desktop\\gameengine\\S24_Qizong_Liang\\Notreal\\Assets\\Shaders\\DefaultFragmentShader.glsl" };

		////////// Texture /////////

		Notreal::Image pic{"C:\\Users\\qizon\\Desktop\\gameengine\\S24_Qizong_Liang\\Notreal\\Assets\\Textures\\test.png"};

		Initialize();

		while (true) 
		{
			OnUpdate();

            Renderer::ClearScreen();

            Renderer::Draw(pic, 200, 100);

			NotrealWindow::GetWindow()->SwapBuffers();
			NotrealWindow::GetWindow()->PollEvents();
		}

		Shutdown();

		NotrealWindow::Shutdown();
	}
}