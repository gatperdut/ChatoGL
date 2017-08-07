#include <iostream>

// ChatoGL
#include "managers/shader_manager.h"
#include "managers/managers.h"
#include "popup.h"

ShaderProgram* ShaderManager::initCommon(std::string vertex, std::string fragment) {
  ShaderProgram* shaderProgram = new ShaderProgram();

  shaderProgram->attach(GL_VERTEX_SHADER, vertex);
  shaderProgram->attach(GL_FRAGMENT_SHADER, fragment);

  shaderProgram->link();

  return shaderProgram;
}

void ShaderManager::initRegular() {
  regular = initCommon("shaders/regular/vertex.glsl", "shaders/regular/fragment.glsl");

  renderMatricesBind(regular);
}

void ShaderManager::initSkybox() {
  skybox = initCommon("shaders/skybox/vertex.glsl", "shaders/skybox/fragment.glsl");

  renderMatricesBind(skybox);
}

void ShaderManager::initShadow() {
  shadow = initCommon("shaders/shadow/vertex.glsl", "shaders/shadow/fragment.glsl");

  renderMatricesBind(shadow);
}

void ShaderManager::initLamp() {
  lamp = initCommon("shaders/lamp/vertex.glsl", "shaders/lamp/fragment.glsl");

  renderMatricesBind(lamp);
}
