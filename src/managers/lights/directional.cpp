// Standard
#include <iostream>

// GLM
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ChatoGL
#include "managers/light_manager.h"
#include "managers/managers.h"
#include "popup.h"
#include "error.h"

void LightManager::directionalLightsStorage() {
  if (BBOdirectionalLights != 0) {
    glDeleteBuffers(1, &BBOdirectionalLights);
  }

  glCreateBuffers(1, &BBOdirectionalLights);
  glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, BBOdirectionalLights);

  glNamedBufferStorage(BBOdirectionalLights, directionalLights.size() * sizeof(DirectionalLightData), NULL, GL_DYNAMIC_STORAGE_BIT);

  directionalLightsData();
}

void LightManager::directionalLightsData() {
  for (unsigned int i = 0; i < directionalLights.size(); i++) {
    glNamedBufferSubData(BBOdirectionalLights, i * sizeof(DirectionalLightData), sizeof(DirectionalLightData), &(directionalLights[i]->data));
  }
}

void LightManager::directionalLightsUpdateShadowTextures() {

  for (unsigned int i = 0; i < directionalLights.size(); i++) {
    directionalLights[i]->readyShaderShadow();
    shaderManager->shadowFramebufferUse();
    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    modelManager->drawAll(shaderManager->shadow);
    glCullFace(GL_BACK);
    glDisable(GL_CULL_FACE);
  }
  shaderManager->shadowFramebufferRelease();
}

void LightManager::directionalLightAdd(glm::vec3 direction, float intensity) {
  DirectionalLight* directionalLight = new DirectionalLight(direction, intensity);
  directionalLights.push_back(directionalLight);
  directionalLightsStorage();
}
