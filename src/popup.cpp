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

  camera = new cam::Camera(glm::vec3(0.0f, 1.0f, 7.0f), w, h);

  // shaders
  shaderManager = new ShaderManager();

  // models
  modelManager = new ModelManager();

  // drawer
  drawer = new Drawer;

  // lights
  lightManager = new LightManager();

  skybox = new Skybox();


  std::string texfilenames[] = {
    "resource/die5.png",
    //"resource/cross.png"
    "resource/terrain.jpg"
  };

  lightManager->directionalLightAdd(glm::vec3(3.0f, 3.0f, 0.0f), 0.7);

  //modelManager->load("resource/cube.obj");
  modelManager->load("resource/bowlingpin/bowlingpin.blend");
  modelManager->load("resource/table/table.blend");

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
