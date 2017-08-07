#include <iostream>

// ChatoGL
#include "managers/shader_manager.h"
#include "managers/managers.h"
#include "popup.h"

void ShaderManager::cameraPositionSet(ShaderProgram* shaderProgram) {
  glUniform3fv(glGetUniformLocation(shaderProgram->id, "campos"), 1, (float*) &(camera->position));
}