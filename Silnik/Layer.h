#pragma once
class Event;
namespace Engine
{
	class Layer
	{
	public:
		virtual ~Layer() = default;
		virtual void onEvent(Event& event) {}
		virtual void onUpdate(float deltaTime) {}
		virtual void onRender() {}
	};
}