#pragma once
#include "Window.h"
#include "Layer.h"
#include <memory>
#include <vector>
namespace Engine
{
	class Application
	{	
		std::vector<std::unique_ptr<Layer>> layers;
		std::shared_ptr<Window> window = nullptr;
	public:
		Application(unsigned int height, unsigned int width);
		template<typename T> requires(std::is_base_of_v<Layer, T>)
		void PushLayer()
		{
			layers.push_back(std::make_unique<T>());
		}
		~Application();
		void Start();
	};
}
