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

	camera = new cam::Camera(glm::vec3(0.0f, 3.0f, 7.0f), w, h);

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

	// GROUND
	btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 0.959);
	btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -.24, 0)));
	btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0, groundMotionState, groundShape, btVector3(0, 0, 0));
	btRigidBody* groundRigidBody = new btRigidBody(groundRigidBodyCI);
	physics->dynamicsWorld->addRigidBody(groundRigidBody);
	modelManager->load("resource/cube/cube.obj", groundRigidBody);

	// BOWLING PIN
	btCollisionShape* fallShape = new btBoxShape(btVector3(0.24, 0.78, 0.24));
	btDefaultMotionState* fallMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 15, 0)));
	btScalar mass = 1;
	btVector3 fallInertia(0, 0, 0);
	fallShape->calculateLocalInertia(mass, fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, fallShape, fallInertia);
	btRigidBody* fallRigidBody = new btRigidBody(fallRigidBodyCI);
	physics->dynamicsWorld->addRigidBody(fallRigidBody);
	modelManager->load("resource/bowlingpin/bowlingpin.obj", fallRigidBody);

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
