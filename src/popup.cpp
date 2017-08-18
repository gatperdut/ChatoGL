// Standard
#include <iostream>
#include <vector>
#include <map>

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

// Custom
#include "window.h"
#include "keyboard.h"
#include "mouse.h"
#include "loop.h"
#include "popup.h"
#include "managers/managers.h"

LightManager* lightManager;

ShaderManager* shaderManager;

ModelManager* modelManager;

Physics* physics;

cam::Camera* camera;

Skybox* skybox;

Drawer* drawer;

int main() {
	GLFWwindow* window;
	int w, h;
	if (init(&window, &w, &h) < 0) {
		return -1;
	}
	std::cout << "OpenGL version " << glGetString(GL_VERSION) << std::endl;

	camera = new cam::Camera(glm::vec3(0.0f, 3.0f, 13.0f), w, h);

	// shaders
	shaderManager = new ShaderManager();

	// models
	modelManager = new ModelManager();

	// drawer
	drawer = new Drawer;

	// lights
	lightManager = new LightManager();

	skybox = new Skybox();

	std::string texfilenames[] = { "resource/die5.png",
	//"resource/cross.png"
			"resource/terrain.jpg" };

	lightManager->directionalLightAdd(glm::vec3(0.1f, 7.0f, 1.0f), 0.7);

	physics = new Physics();

	modelManager->load("resource/cube/cube.obj", "resource/cube/cube.obj", btVector3(0, 0, 0), 0);

	modelManager->load("resource/bowlingpin/bowlingpin.obj", "resource/bowlingpin/bowlingpincollider.obj", btVector3(2, 5, 0), 10);
	modelManager->load("resource/bowlingpin/bowlingpin.obj", "resource/bowlingpin/bowlingpincollider.obj", btVector3(-1, 10, 0), 10);
	modelManager->load("resource/bowlingpin/bowlingpin.obj", "resource/bowlingpin/bowlingpincollider.obj", btVector3(2, 15, 2), 10);
	modelManager->load("resource/bowlingpin/bowlingpin.obj", "resource/bowlingpin/bowlingpincollider.obj", btVector3(2, 25, -1), 10);
	modelManager->load("resource/bowlingpin/bowlingpin.obj", "resource/bowlingpin/bowlingpincollider.obj", btVector3(1, 50, 1), 10);
	modelManager->load("resource/bowlingpin/bowlingpin.obj", "resource/bowlingpin/bowlingpincollider.obj", btVector3(3, 100, 2), 10);
	modelManager->load("resource/bowlingpin/bowlingpin.obj", "resource/bowlingpin/bowlingpincollider.obj", btVector3(-3, 250, -1.5), 10);
	modelManager->load("resource/bowlingpin/bowlingpin.obj", "resource/bowlingpin/bowlingpincollider.obj", btVector3(-2, 300, -2), 10);

	modelManager->load("resource/cube/cube.obj", "resource/cube/cube.obj", btVector3(-5.5, 400, 0), 100);
	modelManager->load("resource/bowlingpin/bowlingpin.obj", "resource/bowlingpin/bowlingpincollider.obj", btVector3(-13, 550, 0), 30);

	modelManager->load("resource/bowlingball/bowlingball.obj", "resource/bowlingball/bowlingball.obj", btVector3(7, 5, 0), 10);

	// io
	Keyboard keyboard(camera);
	Mouse mouse(camera);

	glfwSetKeyCallback(window, Keyboard::callback);
	glfwSetCursorPosCallback(window, Mouse::callback);

	loop(&window, &keyboard, &mouse);

	shutdown();

	delete modelManager;

	return 0;
}
