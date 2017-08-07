#include <iostream>

// GLM
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

// SOIL
#include <SOIL.h>

// ChatoGL
#include "light/directional_light.h"
#include "managers/managers.h"
#include "popup.h"
#include "error.h"

DirectionalLight::DirectionalLight(glm::vec3 direction, float intensity) {
  data.direction = direction;
  data.intensity = intensity;
  data.shininess = 32;
  //data.fragPosLightCoords = glm::vec4(0.0, 0.0, 0.0, 1.0);

  data.projectionMatrix = glm::ortho(-20.0f, 20.0f, -20.0f, 20.0f, 1.0f, 100.0f);
  data.viewMatrix = glm::lookAt(data.direction, glm::vec3(0.0f), glm::vec3(0.0f, 1.0, 0.0));

  //glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "lightSpaceMatrixNoBias"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrixNoBias));
  shadowTextureStorage();

  shadowTextureSampler();

  glMakeTextureHandleResidentARB(data.shadowTextureHandle);
}

DirectionalLight::~DirectionalLight() {

}

void DirectionalLight::shadowTextureStorage() {
  glCreateTextures(GL_TEXTURE_2D, 1, &shadowTextureName);
  //glBindTexture(GL_TEXTURE_2D, shadowTextureName);
  glTextureStorage2D(shadowTextureName, 1, GL_DEPTH_COMPONENT32, 1024, 1024);

  glTextureParameteri(shadowTextureName, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTextureParameteri(shadowTextureName, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTextureParameteri(shadowTextureName, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
  glTextureParameteri(shadowTextureName, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
  glTextureParameteri(shadowTextureName, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  glTextureParameteri(shadowTextureName, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);


  data.shadowTextureHandle = glGetTextureHandleARB(shadowTextureName);
  logErr();
}

void DirectionalLight::shadowTextureSampler() {
//   glCreateSamplers(1, &shadowTextureSamplerName);
//   glSamplerParameteri(shadowTextureSamplerName, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//   glSamplerParameteri(shadowTextureSamplerName, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//   glSamplerParameteri(shadowTextureSamplerName, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
//   glSamplerParameteri(shadowTextureSamplerName, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);

//   glSamplerParameteri(shadowTextureSamplerName, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
//   glSamplerParameteri(shadowTextureSamplerName, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

//   glBindSampler(2, shadowTextureSamplerName);
}

void DirectionalLight::draw(ShaderProgram* shaderProgram) {
  // directional lights are not represented with geometry.
}

void DirectionalLight::readyShaderShadow() {
  shaderManager->shadow->use();
  shaderManager->renderMatrixDataProjection(data.projectionMatrix);

  shaderManager->renderMatrixDataView(data.viewMatrix);

  shaderManager->attachShadowTexture2Framebuffer(shadowTextureName);
  //drawer->drawDepth(shaderProgram);
}
