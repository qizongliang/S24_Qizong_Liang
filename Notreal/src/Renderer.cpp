#include "pch.h"
#include "Renderer.h"

namespace Notreal {
	void Notreal::Renderer::Init()
	{
		if (!mInstance)
			mInstance = new Renderer;
	}

	Renderer* Renderer::GetInstance()
	{
		return mInstance;
	}


	void Renderer::Draw(Image& pic, int x, int y)
	{
		mInstance->mImplementation->Draw(pic, x, y);
	}

}