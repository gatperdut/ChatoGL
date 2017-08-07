#ifndef MOUSE_H
#define MOUSE_H

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

// Custom
#include "camera.h"

class Mouse {
  private:
    cam::Camera* camera;

    struct Pos {
      GLfloat x;
      GLfloat y;
    };

    static Pos last;

    static Pos offset;

    static bool first;

  public:
    Mouse(cam::Camera* camera);
    
    static void callback(GLFWwindow* window, double xpos, double ypos);

    void process();
};

#endif