#include <iostream>

// Custom
#include "keyboard.h"

#include "managers/managers.h"

Keyboard::Keyboard(cam::Camera* camera) {
  this->camera = camera;
}

bool Keyboard::keys[1024] = { false };

void Keyboard::callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
    //lightManager->pointLightAdd(glm::vec3(1.0, 1.5, 1.0), 1.0);
  	lightManager->directionalLightAdd(glm::vec3(0.1f, 8.0f, 0.0f), 0.7);
  }
  if (key == GLFW_KEY_BACKSPACE && action == GLFW_PRESS) {
    lightManager->pointLightRemove(-1);
  }
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }

  if (action == GLFW_PRESS) {
    keys[key] = true;
  }
  else if (action == GLFW_RELEASE) {
    keys[key] = false;
  }
}

void Keyboard::process(GLfloat deltaTime) {
  if (keys[GLFW_KEY_W]) {
    this->camera->processKeyboard(cam::FORWARD, deltaTime);
  }
  if (keys[GLFW_KEY_S]) {
    this->camera->processKeyboard(cam::BACKWARD, deltaTime);
  }
  if (keys[GLFW_KEY_A]) {
    this->camera->processKeyboard(cam::LEFT, deltaTime);
  }
  if (keys[GLFW_KEY_D]) {
    this->camera->processKeyboard(cam::RIGHT, deltaTime);
  }
}
