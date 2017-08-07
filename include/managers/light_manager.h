#ifndef LIGHT_MANAGER_H
#define LIGHT_MANAGER_H

// Standard
#include <vector>

// GLEW
#include <GL/glew.h>
// GLM
#include <glm/glm.hpp>

// ChatoGL
#include "shader/shader_program.h"
#include "light/directional_light.h"
#include "light/point_light.h"
#include "light/spot_light.h"

class LightManager {
  private:
    GLuint BBOdirectionalLights = 0;

    GLuint BBOpointLights = 0;

    GLuint BBOspotLights = 0;

    void directionalLightsStorage();
    void directionalLightsData();

    void pointLightsStorage();
    void pointLightsData();

    void spotLightsStorage();
    void spotLightsData();

    std::vector<DirectionalLight*> directionalLights;

    std::vector<PointLight*> pointLights;

    std::vector<SpotLight*> spotLights;

  public:
    LightManager();

    ~LightManager();

    void directionalLightAdd(glm::vec3 direction, float intensity);
    void remDirectionalLight(int index);
    void directionalLightsUpdateShadowTextures();

    void pointLightAdd(glm::vec3 position, float intensity);
    void pointLightRemove(int index);

    void spotLightAdd(glm::vec3 position, glm::vec3 direction, float cutoff, float intensity);
    void spotLightRemove(int index);

    void drawAll(ShaderProgram* shaderProgram);

    void dataBufferBlocks();
};


#endif
