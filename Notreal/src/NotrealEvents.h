#pragma once

#include "Utility.h"

namespace Notreal
{
	class NOTREAL_API KeyPressed
	{
	public:
		KeyPressed(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class NOTREAL_API KeyReleased
	{
	public:
		KeyReleased(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
	

}