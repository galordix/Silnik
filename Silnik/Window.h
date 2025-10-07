#pragma once

#include "Renderer/Renderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
namespace Engine
{
	class Window
	{
		GLFWwindow* window = nullptr;
		unsigned int height;
		unsigned int width;
	public:
		Window(long height, long width);
		~Window();
		void Create();
		bool ShouldClose();
		static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
		GLFWwindow* GetWindow() const { return window; }
	};
}