#include "Renderer.h"

namespace Engine
{
	void Renderer::Draw(const std::shared_ptr<VertexArray> vertexArray, const std::shared_ptr<Shader> shader, const glm::mat4& transform)
	{
		shader->Bind();
		vertexArray->Bind();
		shader->SetUniformMat4("mvpMatrix", transform);
		glDrawElements(GL_TRIANGLES, vertexArray->GetElementBuffer()->GetCount(), GL_UNSIGNED_INT, 0);
	}
}