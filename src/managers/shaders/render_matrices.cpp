#include <iostream>

#include <glm/gtc/type_ptr.hpp>

// ChatoGL
#include "managers/shader_manager.h"
#include "managers/managers.h"
#include "popup.h"

void ShaderManager::renderMatricesStorage() {
  glCreateBuffers(1, &renderMatricesUBO);
  glBindBuffer(GL_UNIFORM_BUFFER, renderMatricesUBO);
  glNamedBufferStorage(renderMatricesUBO, 2 * sizeof(glm::mat4), NULL, GL_DYNAMIC_STORAGE_BIT);

  renderMatrixDataProjection(camera->getProjectionMatrix());

  glBindBufferBase(GL_UNIFORM_BUFFER, 1, renderMatricesUBO);
}

void ShaderManager::renderMatricesBind(ShaderProgram* shaderProgram) {
  GLuint unifblockindex = glGetUniformBlockIndex(shaderProgram->id, "RenderMatrices");
  glUniformBlockBinding(shaderProgram->id, unifblockindex, 1);
}

void ShaderManager::renderMatrixDataProjection(glm::mat4 projectionMatrix) {
  glNamedBufferSubData(renderMatricesUBO, 0, sizeof(glm::mat4), glm::value_ptr(projectionMatrix));
}

void ShaderManager::renderMatrixDataView(glm::mat4 viewMatrix) {
  glNamedBufferSubData(renderMatricesUBO, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(viewMatrix));
}
