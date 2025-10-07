#pragma once
#include <cstdint>
namespace Engine
{
	class ElementBuffer
	{
	public:
		ElementBuffer();
		ElementBuffer(const uint32_t* indices, const uint32_t count);
		void Bind() const;
		void Unbind() const;
		inline uint32_t GetCount() const { return count; }
		~ElementBuffer();
	private:
		uint32_t count;
		uint32_t bufferID;
	};
}