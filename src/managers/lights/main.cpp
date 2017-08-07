// Standard
#include <iostream>

// GLM
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ChatoGL
#include "managers/light_manager.h"
#include "popup.h"

LightManager::LightManager() {
}

LightManager::~LightManager() {
}

void LightManager::dataBufferBlocks() {
  directionalLightsData();
  pointLightsData();
  spotLightsData();
}

void LightManager::drawAll(ShaderProgram* shaderProgram) {
  std::vector<DirectionalLight*>::iterator iterDirectionalLight;
  for (iterDirectionalLight = directionalLights.begin(); iterDirectionalLight != directionalLights.end(); iterDirectionalLight++) {
    (*iterDirectionalLight)->draw(shaderProgram);
  }

  std::vector<PointLight*>::iterator iterPointLight;
  for (iterPointLight = pointLights.begin(); iterPointLight != pointLights.end(); iterPointLight++) {
    (*iterPointLight)->draw(shaderProgram);
  }

  std::vector<SpotLight*>::iterator iterSpotLight;
  for (iterSpotLight = spotLights.begin(); iterSpotLight != spotLights.end(); iterSpotLight++) {
    (*iterSpotLight)->draw(shaderProgram);
  }
}
