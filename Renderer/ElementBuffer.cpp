#include "ElementBuffer.h"
#include <glad/glad.h>
namespace Engine
{
	ElementBuffer::ElementBuffer()
		: count(0)
	{
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	ElementBuffer::ElementBuffer(const uint32_t* indices, const uint32_t count)
		: count(count)
	{
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glBufferData(GL_ARRAY_BUFFER, count, indices, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void ElementBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	}

	void ElementBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	ElementBuffer::~ElementBuffer()
	{
		glDeleteBuffers(1, &bufferID);
	}
}