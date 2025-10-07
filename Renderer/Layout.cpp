#include "Layout.h"
namespace Engine
{
	Layout::Layout(std::initializer_list<LayoutElement> elements)
		: elements(elements)
	{
		CalculateStrideAndOffsets();
	}

	void Layout::CalculateStrideAndOffsets()
	{
		size_t offset = 0;
		stride = 0;
		for (auto& element : elements)
		{
			element.offset = offset;
			offset += element.size;
			stride += element.size;
		}
	}
}