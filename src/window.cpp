// Standard
#include <iostream>

// GLEW
#include <GL/glew.h>

// Custom
#include "window.h"
#include "error.h"

GLint init(GLFWwindow** window, int* w, int* h) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

  *window = glfwCreateWindow(1024, 1024, "PopUp", NULL, NULL);
  if (*window == NULL) {
    std::cerr << "GLFW::WINDOWF failed." << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(*window);
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cerr << "GLEW::INIT failed." << std::endl;
    glfwTerminate();
    return -1;
  }
  glGetError();

  glDebugMessageCallback(debugCallback, NULL);
  glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
  glfwGetFramebufferSize(*window, w, h);
  glViewport(0, 0, *w, *h);

  glEnable(GL_DEPTH_TEST);

  glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  return 0;
}

void clear() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void swap(GLFWwindow** window) {
  glfwSwapBuffers(*window);
}

void shutdown() {
  glfwTerminate();
}
