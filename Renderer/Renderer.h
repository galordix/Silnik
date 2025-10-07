#pragma once

#include "glad/glad.h"
#include <string>
#include <glm/mat4x4.hpp>
#include "Shader.h"
#include "VertexArray.h"
namespace Engine
{
	class Renderer
	{
		
	public:
		
		void Draw(const std::shared_ptr<VertexArray> vertexArray, const std::shared_ptr<Shader> shader,
			const glm::mat4& transform = glm::mat4(1.0f));
	private:
		glm::mat4 viewProjectionMatrix;
	};
}

