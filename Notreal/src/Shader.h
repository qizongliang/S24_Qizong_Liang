#pragma once

#include "pch.h"
#include"Utility.h"
#include "ShaderImplement.h"

namespace Notreal 
{
	class NOTREAL_API Shader 
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		Shader(std::string&& vertexFile, std::string&& fragmentFile);

		void Bind();

	private:
		std::unique_ptr<ShaderImplement> mImplementation;
	};
}