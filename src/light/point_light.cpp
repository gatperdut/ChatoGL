#include <iostream>

// GLM
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

// SOIL
#include <SOIL.h>

// ChatoGL
#include "light/point_light.h"
#include "managers/managers.h"
#include "popup.h"

PointLight::PointLight(glm::vec3 pos, float intensity) {
  this->data.pos = pos;
  this->data.intensity = intensity;
  this->data.shininess = 32;
  this->data.attenuation.constant = 1.0;
  this->data.attenuation.linear = 0.35;
  this->data.attenuation.quadratic = 0.44;

  setData();
}

PointLight::~PointLight() {

}

void PointLight::setData() {
  glCreateVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  glCreateBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glNamedBufferStorage(VBO, sizeof(float) * 36 * 3, geometry, GL_DYNAMIC_STORAGE_BIT);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
  glEnableVertexAttribArray(0);
}

void PointLight::draw(ShaderProgram* shaderProgram) {
  glBindVertexArray(VAO);

  //data.pos.z = sin((GLfloat) glfwGetTime() / 2.0) * 5.0f + 2;
  glm::mat4 modelMatrix;
  modelMatrix = glm::translate(modelMatrix, data.pos);
  modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15));

  glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "model"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
  glUniform1f(glGetUniformLocation(shaderProgram->id, "intensity"), data.intensity);

  glDrawArrays(GL_TRIANGLES, 0, 36);
}
