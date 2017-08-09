// Standard
#include <iostream>

// GLM
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ChatoGL
#include "managers/light_manager.h"
#include "popup.h"



void LightManager::pointLightsStorage() {
  if (BBOpointLights != 0) {
    glDeleteBuffers(1, &BBOpointLights);
  }

  glCreateBuffers(1, &BBOpointLights);
  glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, BBOpointLights);

  glNamedBufferStorage(BBOpointLights, pointLights.size() * sizeof(PointLightData), NULL, GL_DYNAMIC_STORAGE_BIT);

  pointLightsData();
}

void LightManager::pointLightsData() {
  for (unsigned int i = 0; i < pointLights.size(); i++) {
    glNamedBufferSubData(BBOpointLights, i * sizeof(PointLightData), sizeof(PointLightData), &(pointLights[i]->data));
  }
}

void LightManager::pointLightAdd(glm::vec3 position, float intensity) {
  PointLight* pointLight = new PointLight(position, intensity);
  pointLights.push_back(pointLight);

  pointLightsStorage();
}

void LightManager::pointLightRemove(int index) {
  if (index < -1) {
    std::cerr << "Provide a valid index, or -1 to remove last pointlight.";
    return;
  }
  if (pointLights.size() == 0) {
    std::cerr << "No pointlights to remove." << std::endl;
    return;
  }
  if (index == -1) {
    index = pointLights.size() - 1;
  }

  pointLights.erase(pointLights.begin() + index);

  pointLightsStorage();
}
