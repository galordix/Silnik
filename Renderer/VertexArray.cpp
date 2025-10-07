#include "VertexArray.h"
#include <glad/glad.h>
namespace Engine
{
	void VertexArray::Bind() const
	{
		glBindVertexArray(arrayID);
	}
	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void VertexArray::AddVertexBuffer(std::shared_ptr<VertexBuffer> vertexBuffer)
	{
		Bind();
		vertexBuffer->Bind();
		Layout layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(attributeIndex);


		}
		vertexBuffers.push_back(vertexBuffer);
		Unbind();
	}

	void VertexArray::SetElementBuffer(std::shared_ptr<ElementBuffer> elementBuffer)
	{
		Bind();
		elementBuffer->Bind();
		this->elementBuffer = elementBuffer;
		Unbind();
	}

}