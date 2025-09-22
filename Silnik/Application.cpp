#include "Application.h"
namespace Engine
{
	Application::Application(unsigned int height, unsigned int width)
	{
		window = std::make_shared<Window>(height, width);
		window->Create();
	}
	void Application::Start()
	{
		bool running = true;
		while (running)
		{
			glfwPollEvents();
			if (window->ShouldClose())
			{
				running = false;
				break;
			}


			for (auto& layer : layers)
			{
				layer->onRender();
			}
			glfwSwapBuffers(window->GetWindow());
			
		}
		
	}
	Application::~Application()
	{
		window = nullptr;
	}
}
