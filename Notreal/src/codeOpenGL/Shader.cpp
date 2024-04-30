#include "pch.h"
#include "Shader.h"

namespace Notreal 
{
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef NOTREAL_OPENGL
		mImplementation = std::unique_ptr<ShaderImplement>{ new ShaderOpenGL{vertexFile,fragmentFile} };
#else
		#only_openGL_is_supported_so_far

#endif
	}
	Shader::Shader(std::string&& vertexFile, std::string&& fragmentFile)
	{
#ifdef NOTREAL_OPENGL
		mImplementation = std::unique_ptr<ShaderImplement>{ new ShaderOpenGL{move(vertexFile),move(fragmentFile)} };
#else
		#only_openGL_is_supported_so_far

#endif
	}
	void Shader::Bind()
	{
		mImplementation->Bind();
	}
}