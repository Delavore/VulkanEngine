#include "lve_window.hpp"

namespace lve {
	LveWindow::LveWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LveWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);  // saying GLFW not create openGL context
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);  // being resized after creating

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
}