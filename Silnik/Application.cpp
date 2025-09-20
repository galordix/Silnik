#include "Application.h"
namespace Engine
{
	Application::Application(unsigned int height, unsigned int width)
	{
		window = std::make_shared<Window>(height, width);
		window->Create();
		MainLoop();
	}
	void Application::MainLoop()
	{
		
		while (!window->ShouldClose())
		{
			glfwPollEvents();
			glfwSwapBuffers(window->GetWindow());
		}
		
	}
	Application::~Application()
	{
		window = nullptr;
	}
}
