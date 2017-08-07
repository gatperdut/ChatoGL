#ifndef CAMERA_H
#define CAMERA_H

// GLM
#include <glm/gtc/matrix_transform.hpp>
// GLEW
#include <GL/glew.h>

// ChatoGL
#include "shader/shader_program.h"

namespace cam {

  enum Direction {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
  };

  class Camera {
    private:
      struct Orientation {
        GLfloat yaw;
        GLfloat pitch;
      };

      struct CoordSystem {
        glm::vec3 front;
        glm::vec3 up;
        glm::vec3 right;
      };

      struct Options {
        GLfloat mouseSensitivity;
        GLfloat movementSpeed;
        GLfloat zoom;
      };

      GLfloat ratio;
      CoordSystem coordSystem;
      Orientation orientation;
      glm::vec3 worldUp;
      Options options;

      void updateCoordSystem();

    public:

      Camera(glm::vec3 position, int width, int height);

      glm::mat4 getViewMatrix();

      glm::mat4 getProjectionMatrix();

      void processMouse(GLfloat xOffset, GLfloat yOffset);

      void processKeyboard(Direction direction, GLfloat deltaTime);

      GLfloat getZoom();

      glm::vec3 position;
  };

}

#endif