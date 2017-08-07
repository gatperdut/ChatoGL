// Standard
#include <iostream>

// GLM
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ChatoGL
#include "managers/light_manager.h"
#include "popup.h"

void LightManager::spotLightsStorage() {
  if (BBOspotLights != 0) {
    glDeleteBuffers(1, &BBOspotLights);
  }

  glGenBuffers(1, &BBOspotLights);
  glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, BBOspotLights);

  glNamedBufferStorage(BBOspotLights, spotLights.size() * sizeof(SpotLightData), NULL, GL_DYNAMIC_STORAGE_BIT);
  spotLightsData();
}

void LightManager::spotLightsData() {
  for (unsigned int i = 0; i < spotLights.size(); i++) {
    glNamedBufferSubData(BBOspotLights, i * sizeof(SpotLightData), sizeof(SpotLightData), &(spotLights[i]->data));
  }
}

void LightManager::spotLightAdd(glm::vec3 position, glm::vec3 direction, float cutoff, float intensity) {
  SpotLight* spotLight = new SpotLight(position, direction, cutoff, intensity);
  spotLights.push_back(spotLight);

  spotLightsStorage();
}

void LightManager::spotLightRemove(int index) {
  if (index < -1) {
    std::cerr << "Provide a valid index, or -1 to remove last spotlight.";
    return;
  }
  if (spotLights.size() == 0) {
    std::cerr << "No spotlights to remove." << std::endl;
    return;
  }
  if (index == -1) {
    index = spotLights.size() - 1;
  }

  spotLights.erase(spotLights.begin() + index);

  spotLightsStorage();
}
