#include "Window.h"
#include <iostream>
namespace Engine
{
	Window::Window(long height, long width) 
		: height(height), width(width)
	{	
	}

	Window::~Window()
	{
		glfwTerminate();
		window = nullptr;
	}
	void Window::Create()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		window = glfwCreateWindow(width, height, "Game", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return;
		}
		glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
		glViewport(0, 0, width, height);
	}
	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(window);
	}
	void Window::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}