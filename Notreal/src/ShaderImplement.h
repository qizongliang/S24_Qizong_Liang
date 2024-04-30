#pragma once

namespace Notreal 
{
	class ShaderImplement 
	{
	public:
		virtual void Bind() = 0;

		virtual ~ShaderImplement() {};
	};
}