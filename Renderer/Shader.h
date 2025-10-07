#pragma once
#include <string>
#include <unordered_map>
#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Engine
{
	class Shader
	{
	public:
		Shader();
		Shader(const char* vertexPath, const char* fragmentPath);
		void Bind();
		void Unbind();
		void CreateShaderProgram(const char* vertexPath, const char* fragmentPath);
		uint32_t CompileShader(const char* source, GLenum shaderType);
		std::string LoadShader(const char* path);

		void SetUniformMat4(const std::string& name, const glm::mat4& data);
		void SetUniformVec2(const std::string& name, const glm::vec2& data);
		void SetUniformVec3(const std::string& name, const glm::vec3& data);
		void SetUniformVec4(const std::string& name, const glm::vec4& data);
		void SetUniformFloat(const std::string& name, const float& data);
		void SetUniformInt(const std::string& name, const int& data);
		void SetUniformUint(const std::string& name, const uint32_t& data);
	private:
		uint32_t shaderID;
	};
}
