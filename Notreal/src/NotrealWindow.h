#pragma once
#include"WindowImpl.h"
#include"Utility.h"

namespace Notreal
{
	class NOTREAL_API NotrealWindow 
	{
	public:
		static void Init();
		static NotrealWindow* GetWindow();

		void Create(int width, int height);
		int GetWidth() const;
		int GetHeight() const;


	private:
		inline static NotrealWindow* mInstance{ nullptr };

		std::unique_ptr<WindowImpl> mWindow{nullptr};
		NotrealWindow();

	};
}