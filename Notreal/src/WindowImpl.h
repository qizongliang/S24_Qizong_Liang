#pragma once

namespace Notreal 
{
	class WindowImpl 
	{
	public:
		virtual void Create(int width, int height)=0;
		virtual int GetWidth() const=0;
		virtual int GetHeight() const=0;
		virtual ~WindowImpl() {};
	};
}