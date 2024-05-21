#include "pch.h"
#include "NotrealEvents.h"

namespace Notreal 
{
	KeyPressed::KeyPressed(int kCode):mKeyCode(kCode)
	{

	}
	int KeyPressed::GetKeyCode() const
	{
		return mKeyCode;
	}
	KeyReleased::KeyReleased(int kCode):mKeyCode(kCode)
	{
	}
	int KeyReleased::GetKeyCode() const
	{
		return mKeyCode;
	}
}