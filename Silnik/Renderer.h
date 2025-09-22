#pragma once

#include "Window.h"
#include "glad/glad.h"
#include <string>
namespace Engine
{
	class Renderer
	{
		
	public:
		static GLuint CreateShaderProgram(const char* vertexPath, const char* fragmentPath);
		static GLuint CompileShader(const char* source, GLenum shaderType);
		static std::string LoadShader(const char* path);

		static void InitBuffers(GLuint& vertexArray, GLuint& vertexBuffer, GLuint& elementBuffer, GLuint& instanceBuffer);
	protected:

	};
}

