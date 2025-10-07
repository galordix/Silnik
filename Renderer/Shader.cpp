#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
namespace Engine
{
	std::string Shader::LoadShader(const char* path)
	{
		std::ifstream file(path);
		if (!file.is_open())
			throw std::runtime_error("Failed to open File");
		std::string shader;
		for (std::string line; std::getline(file, line); )
		{
			shader += line + "\n";
		}
		return shader;
	}
	
	GLuint Shader::CompileShader(const char* source, GLenum shaderType)
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


	Shader::Shader()
	{
		shaderID = 0;
	}

	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		CreateShaderProgram(vertexPath, fragmentPath);
	}

	void Shader::Bind()
	{
		glUseProgram(shaderID);
	}
	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::CreateShaderProgram(const char* vertexPath, const char* fragmentPath) {
		// Load shader source
		std::string vertexCode = LoadShader(vertexPath);
		std::string fragmentCode = LoadShader(fragmentPath);

		// Compile shaders
		GLuint vertexShader = CompileShader(vertexCode.c_str(), GL_VERTEX_SHADER);
		GLuint fragmentShader = CompileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

		// Link shaderID
		GLuint shaderID = glCreateProgram();
		glAttachShader(shaderID, vertexShader);
		glAttachShader(shaderID, fragmentShader);
		glLinkProgram(shaderID);

		// Check for linking errors
		GLint success;
		glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(shaderID, 512, nullptr, infoLog);
			throw std::runtime_error("Program linking failed: " + std::string(infoLog));
		}

		// Shaders can be deleted after linking
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	void Shader::SetUniformMat4(const std::string& name, const glm::mat4& data)
	{
		GLuint location = glGetUniformLocation(shaderID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(data));
	}
	void Shader::SetUniformVec2(const std::string& name, const glm::vec2& data)
	{
		GLuint location = glGetUniformLocation(shaderID, name.c_str());
		glUniform2f(location, data.x, data.y);
	}
	void Shader::SetUniformVec3(const std::string& name, const glm::vec3& data)
	{
		GLuint location = glGetUniformLocation(shaderID, name.c_str());
		glUniform3f(location, data.x, data.y, data.z);
	}
	void Shader::SetUniformVec4(const std::string& name, const glm::vec4& data)
	{
		GLuint location = glGetUniformLocation(shaderID, name.c_str());
		glUniform4f(location, data.x, data.y, data.z, data.w);
	}
	void Shader::SetUniformInt(const std::string& name, const int& data)
	{
		GLuint location = glGetUniformLocation(shaderID, name.c_str());
		glUniform1i(location, data);
	}
	void Shader::SetUniformUint(const std::string& name, const uint32_t& data)
	{
		GLuint location = glGetUniformLocation(shaderID, name.c_str());
		glUniform1ui(location, data);
	}
	void Shader::SetUniformFloat(const std::string& name, const float& data)
	{
		GLuint location = glGetUniformLocation(shaderID, name.c_str());
		glUniform1f(location, data);
	}
}