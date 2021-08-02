#include <GLFW/glfw3.h>
#include <iostream>

static void HandleKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(int args, char** argv)
{
	if (glfwInit() != GLFW_TRUE)
	{
		std::cerr << "GLFW not ok" << std::endl;
		return EXIT_FAILURE;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Empty", NULL, NULL);

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, HandleKeyboardInput);

	if (!window)
	{
		std::cerr << "Window failed" << std::endl;
		return EXIT_FAILURE;
	}

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();

	return EXIT_SUCCESS;
}

static void HandleKeyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	std::cout << "key: " << key << ", scancode: " << scancode << ", action: " << action << ", mods: " << mods << std::endl;
}