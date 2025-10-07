#pragma once
#include "Layout.h"
#include <memory>
#include <string>
#include <vector>
namespace Engine
{
	
	class VertexBuffer
	{
	public:
		VertexBuffer();
		VertexBuffer(const void* data, uint32_t size);
		void Bind();
		void Unbind();
		void SetData(const void* data, uint32_t size);

		inline Layout GetLayout() const { return layout; }
		~VertexBuffer();
	private:
		Layout layout;
		unsigned int bufferID;
	};
}


