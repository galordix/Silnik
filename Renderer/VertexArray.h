#pragma once
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include <memory>
#include <vector>
namespace Engine
{
	class VertexArray
	{
	public:
		void Bind() const;
		void Unbind() const;

		void AddVertexBuffer(std::shared_ptr<VertexBuffer> vertexBuffer);
		void SetElementBuffer(std::shared_ptr<ElementBuffer> elementBuffer);


		inline std::shared_ptr<ElementBuffer> GetElementBuffer() const { return elementBuffer; }
	private:
		uint32_t arrayID;
		uint32_t attributeIndex = 0;
		std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers;
		std::shared_ptr<ElementBuffer> elementBuffer;
	};
}


