#pragma once
#include <vector>
namespace Engine
{
	enum ElementType
	{
		None = 0, Float, Vec2, Vec3, Vec4, Mat3, Mat4, Int, Ivec2, Ivec3, Ivec4
	};

	static uint32_t ElementTypeSize(ElementType type)
	{
		switch (type)
		{
		case ElementType::Float: return 4; // 4 * 1
		case ElementType::Vec2: return 8; // 4 * 2
		case ElementType::Vec3: return 12; // 4 * 3
		case ElementType::Vec4: return 16; // 4 * 4
		case ElementType::Mat3: return 36; // 4 * 3 * 3
		case ElementType::Mat4: return 64; // 4 * 4 * 4
		case ElementType::Int: return 4; // 4 * 1
		case ElementType::Ivec2: return 8; // 4 * 2
		case ElementType::Ivec3: return 12; // 4 * 3
		case ElementType::Ivec4: return 16; // 4 * 4
		}
	};
	struct LayoutElement
	{
	public:
		ElementType type;
		std::string name;
		uint32_t size;
		uint32_t offset;


		LayoutElement(const std::string& name, ElementType type)
			: name(name), type(type), offset(0), size(ElementTypeSize(type))
		{

		}

		uint32_t GetComponentCount() const
		{
			switch (type)
			{
			case ElementType::Float: return 1;
			case ElementType::Vec2: return 2;
			case ElementType::Vec3: return 3;
			case ElementType::Vec4: return 4;
			case ElementType::Mat3: return 3;
			case ElementType::Mat4: return 4;
			case ElementType::Int: return 1;
			case ElementType::Ivec2: return 2;
			case ElementType::Ivec3: return 3;
			case ElementType::Ivec4: return 4;
			}
		}

	};
	struct Layout
	{
	public:
		Layout(std::initializer_list<LayoutElement> elements);
		
		std::vector<LayoutElement>::iterator begin() { return elements.begin(); }
		std::vector<LayoutElement>::iterator end() { return elements.end(); }
		std::vector<LayoutElement>::const_iterator begin() const { return elements.begin(); }
		std::vector<LayoutElement>::const_iterator end() const { return elements.end(); }

		inline std::vector<LayoutElement> GetElements() const { return elements; }
	private:
		void CalculateStrideAndOffsets();
		std::vector<LayoutElement> elements;
		uint32_t stride;
	};
}

