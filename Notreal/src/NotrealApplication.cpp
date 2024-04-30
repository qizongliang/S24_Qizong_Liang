#include "pch.h"

#include "NotrealWindow.h"
#include "NotrealApplication.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include "Image.h"
#include "Shader.h"

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

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			NOTREAL_ERROR("Failed to initialize GLAD");
			return;
		}
		////////// Blending///////////
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		////// Vertex Data //////////
		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		float vertices[]{
			-0.5f,-0.5f, 0.0, 0.0, // left
			0.5f,-0.5f, 1.0, 0.0, // right
			-0.5f,0.5f, 0.0, 1.0, // top
			0.5f,0.5f, 1.0, 1.0 // left
		};

		unsigned int indices[]
		{
			0,1,2,//first triangle
			1,2,3
		};

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 *sizeof(float)) );
		glEnableVertexAttribArray(1);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		///////// Sharders ///////

		Shader sProg{"C:\\Users\\qizon\\source\\repos\\S24_Qizong_Liang\\Notreal\\Assets\\Shaders\\DefaultVertexShader.glsl","C:\\Users\\qizon\\source\\repos\\S24_Qizong_Liang\\Notreal\\Assets\\Shaders\\DefaultFragmentShader.glsl" };

		////////// Texture /////////

		Notreal::Image pic{"C:\\Users\\qizon\\source\\repos\\S24_Qizong_Liang\\Notreal\\Assets\\Textures\\test.png"};

		Initialize();

		while (true) 
		{
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// draw our first triangle
			sProg.Bind();
			glBindVertexArray(VAO); // Seeing as we only have a single VAO there's noi need to bind it every time
			pic.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			NotrealWindow::GetWindow()->SwapBuffers();
			NotrealWindow::GetWindow()->PollEvents();
		}

		Shutdown();

		NotrealWindow::Shutdown();
	}
}