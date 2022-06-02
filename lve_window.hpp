#pragma once

#define GLFW_INCLUDE_VULKAN
#include <string>
#include <GLFW/glfw3.h>


namespace lve
{
	class LveWindow
	{
	public:
		LveWindow(int w, int h, std::string name);
		~LveWindow();

		bool shouldClose();
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
		VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }

		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;

	private:
		void initWindow();

		const int width;
		const int height;
		std::string windowName;
		GLFWwindow* window;
	};

};