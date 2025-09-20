#pragma once

#include "Window.h"
#include <string>
namespace Engine
{
	class Renderer
	{
		
	public:
		GLuint CreateShaderProgram(const char* vertexPath, const char* fragmentPath);
		GLuint CompileShader(const char* source, GLenum shaderType);
		std::string LoadShader(const char* path);
	protected:
	};
}

