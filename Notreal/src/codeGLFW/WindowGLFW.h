#pragma once
#include"../WindowImpl.h"
#include"GLFW/glfw3.h"

namespace Notreal 
{
	class WindowGLFW : public WindowImpl
	{
	public:
		WindowGLFW();
		virtual void Create(int width, int height) override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		~WindowGLFW();

	private:
		GLFWwindow* mWindow{ nullptr };

	};
}