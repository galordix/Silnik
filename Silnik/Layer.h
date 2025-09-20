#pragma once
namespace Engine
{
	class Layer
	{
	public:
		virtual ~Layer() = default;
		virtual void onEvent() {}
		virtual void onUpdate(float deltaTime) {}
		virtual void onRender() {}
	};
}