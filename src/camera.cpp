// Standard
#include <iostream>

// Custom
#include "camera.h"

namespace cam {

  Camera::Camera(glm::vec3 position, int width, int height) {
    this->position = position;

    this->ratio = (GLfloat) width / height;

    this->coordSystem.front = glm::vec3(0.0f, 0.0f, -1.0f);

    this->orientation.yaw = -90.0f;
    this->orientation.pitch = 0.0f;

    this->worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    this->options.mouseSensitivity = 0.08f;
    this->options.movementSpeed = 3.0f;
    this->options.zoom = 45.0;

    this->updateCoordSystem();
  }

  void Camera::updateCoordSystem() {
    glm::vec3 front;
    front.x = cos(glm::radians(this->orientation.yaw)) * cos(glm::radians(this->orientation.pitch));
    front.y = sin(glm::radians(this->orientation.pitch));
    front.z = sin(glm::radians(this->orientation.yaw)) * cos(glm::radians(this->orientation.pitch));

    this->coordSystem.front = glm::normalize(front);
    this->coordSystem.right = glm::normalize(glm::cross(this->coordSystem.front, this->worldUp));
    this->coordSystem.up    = glm::normalize(glm::cross(this->coordSystem.right, this->coordSystem.front));
  }

  glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(this->position, this->position + this->coordSystem.front, this->coordSystem.up);
  }

  glm::mat4 Camera::getProjectionMatrix() {
    return glm::perspective(this->getZoom(), this->ratio, 0.1f, 100.0f);
  }

  void Camera::processMouse(GLfloat xOffset, GLfloat yOffset) {
    this->orientation.yaw   += xOffset * this->options.mouseSensitivity;
    this->orientation.pitch += yOffset * this->options.mouseSensitivity;

    if (this->orientation.pitch >  89.0) {
      this->orientation.pitch =  89.0;
    }
    if (this->orientation.pitch < -89.0) {
      this->orientation.pitch = -89.0;
    }

    this->updateCoordSystem();
  }

  void Camera::processKeyboard(Direction direction, GLfloat deltaTime) {
    glm::vec3 increase;
    switch(direction) {
      case FORWARD:
        increase =  this->coordSystem.front;
        break;
      case BACKWARD:
        increase = -this->coordSystem.front;
        break;
      case LEFT:
        increase = -this->coordSystem.right;
        break;
      case RIGHT:
        increase =  this->coordSystem.right;
        break;
      default:
        std::cerr << "CAMERA::KEYBOARD unknown direction." << std::endl;
    }

    GLfloat velocity = this->options.movementSpeed * deltaTime;

    this->position += increase * velocity;
  }

  GLfloat Camera::getZoom() {
    return this->options.zoom;
  }

}