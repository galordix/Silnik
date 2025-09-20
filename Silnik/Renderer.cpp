#include "Renderer.h"
#include <iostream>
#include <fstream>
namespace Engine
{
	std::string Renderer::LoadShader(const char* path)
	{
		std::ifstream file(path);
		std::string shader;
		for (std::string line; std::getline(file, line); )
		{
			shader += line + "\n";
		}
		return shader;
	}
	GLuint Renderer::CompileShader(const char* source, GLenum shaderType)
	{
		GLuint shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &source, nullptr);
		glCompileShader(shader);

		// Check for compilation errors
		GLint success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			throw std::runtime_error("Shader compilation failed: " + std::string(infoLog));
		}

		return shader;
	}

	GLuint Renderer::CreateShaderProgram(const char* vertexPath, const char* fragmentPath) {
		// Load shader source
		std::string vertexCode = LoadShader(vertexPath);
		std::string fragmentCode = LoadShader(fragmentPath);

		// Compile shaders
		GLuint vertexShader = CompileShader(vertexCode.c_str(), GL_VERTEX_SHADER);
		GLuint fragmentShader = CompileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

		// Link program
		GLuint program = glCreateProgram();
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);

		// Check for linking errors
		GLint success;
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(program, 512, nullptr, infoLog);
			throw std::runtime_error("Program linking failed: " + std::string(infoLog));
		}

		// Shaders can be deleted after linking
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return program;
	}
}