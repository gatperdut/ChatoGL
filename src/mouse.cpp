// Custom
#include "mouse.h"

Mouse::Mouse(cam::Camera* camera) {
  this->camera = camera;
}

bool Mouse::first = true;

Mouse::Pos Mouse::last = { 0.0f, 0.0f };
Mouse::Pos Mouse::offset = { 0.0f, 0.0f };

void Mouse::callback(GLFWwindow* window, double xpos, double ypos) {
  if (first) {
    last.x = xpos;
    last.y = ypos;
    first = false;
  }

  offset.x = xpos - last.x;
  offset.y = last.y - ypos;
  last.x = xpos;
  last.y = ypos;
}

void Mouse::process() {
  this->camera->processMouse(offset.x, offset.y);
  offset.x = 0.0f;
  offset.y = 0.0f;
}
