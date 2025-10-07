#include "VertexBuffer.h"
#include <glad/glad.h>
namespace Engine
{
	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &bufferID);
		this->Bind();
		glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);
		this->Unbind();
	}
	VertexBuffer::VertexBuffer(const void* data, uint32_t size)
	{
		glGenBuffers(1, &bufferID);
		this->Bind();
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
		this->Unbind();
	}
	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	}
	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::SetData(const void* data, uint32_t size)
	{
		Bind();
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &bufferID);
	}
}