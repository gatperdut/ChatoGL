#include <iostream>

// ChatoGL
#include "managers/shader_manager.h"
#include "managers/managers.h"
#include "popup.h"

ShaderManager::ShaderManager() {
  shadowFramebufferStorage();

  initRegular();
  initSkybox();
  initShadow();
  initLamp();

  renderMatricesStorage();
}

ShaderManager::~ShaderManager() {
  delete regular;
  delete skybox;
  delete shadow;
  delete lamp;
}
