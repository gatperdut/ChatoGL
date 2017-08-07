#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

// GLM
#include <glm/glm.hpp>

// ChatoGL
#include "shader/shader_program.h"

struct DirectionalLightData {
  GLuint64 shadowTextureHandle;
  float intensity;
  float shininess;
  glm::vec3 direction;
  float _padding[1];
  glm::mat4 viewMatrix;
  glm::mat4 projectionMatrix;
};

class DirectionalLight {
  private:
    GLuint shadowTextureName;
    GLuint shadowTextureSamplerName;

    void shadowTextureStorage();
    void shadowTextureSampler();

  public:
    DirectionalLight(glm::vec3 direction, float intensity);

    ~DirectionalLight();

    GLuint64 shadowTextureHandle;

    glm::mat4 projectionMatrix;

    DirectionalLightData data;

    void readyShaderShadow();

    void draw(ShaderProgram* shaderProgram);
};

#endif
