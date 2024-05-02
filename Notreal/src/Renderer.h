#pragma once

#include "pch.h"
#include "Utility.h"
#include "Image.h"


namespace Notreal 
{
	class NOTREAL_API Renderer 
	{
	public:
		static void Init();
		static Renderer* GetInstance();

		static void Draw(Image& pic, int x, int y);
		

	private:
		std::unique_ptr<RendererImplement> mImplementation;

		inline static Renderer* mInstance{ nullptr };
		Renderer();

	};
}