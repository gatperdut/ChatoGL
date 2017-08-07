#ifndef KEYBOARD_H
#define KEYBOARD_H

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

// Custom
#include "camera.h"

class Keyboard {
  private:
    cam::Camera* camera;

    static bool keys[1024];

  public:
    Keyboard(cam::Camera* camera);
    
    static void callback(GLFWwindow* window, int key, int scancode, int action, int mode);

    void process(GLfloat deltaTime);
};

#endif
