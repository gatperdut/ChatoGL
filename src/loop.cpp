#include <iostream>

// Custom
#include "loop.h"
#include "window.h"
#include "error.h"
#include "popup.h"

void loop(GLFWwindow** window, Keyboard* keyboard, Mouse* mouse) {
  GLfloat currentFrame;  // TODO wrap in struct
  GLfloat deltaTime;
  GLfloat lastFrame = 0.0f;

  while (!glfwWindowShouldClose(*window)) {
    currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;


    glfwPollEvents();

    clear();

    drawer->draw();

    keyboard->process(deltaTime);

    mouse->process();

    swap(window);
  }
}
