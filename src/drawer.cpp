// Standard
#include <iostream>
#include <vector>
#include <string>

// GLM
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// SOIL
#include <SOIL.h>

// Custom
#include "popup.h"
#include "drawer.h"
#include "managers/managers.h"

Drawer::Drawer() {

}

Drawer::~Drawer() {

}

void Drawer::draw() {
  shaderManager->renderMatrixDataView(camera->getViewMatrix());

  skybox->draw();

  shaderManager->lamp->use();
  lightManager->drawAll(shaderManager->lamp);

  //DirectionalLight* dlight = lightManager->dirtyGet();

  // shaderManager->shadowFramebufferUse();
  // dlight->readyShaderShadow();
  // glClear(GL_DEPTH_BUFFER_BIT);
  // glEnable(GL_CULL_FACE);
  // glCullFace(GL_FRONT);
  // modelManager->drawAll(shaderManager->shadow);
  // glCullFace(GL_BACK);
  // glDisable(GL_CULL_FACE);
  // shaderManager->shadowFramebufferRelease();

  //lightManager->directionalLightsUpdateShadowTextures();

  shaderManager->regular->use();
  shaderManager->renderMatrixDataProjection(camera->getProjectionMatrix());
  shaderManager->renderMatrixDataView(camera->getViewMatrix());
  shaderManager->cameraPositionSet(shaderManager->regular);
  modelManager->drawAll(shaderManager->regular);
  lightManager->dataBufferBlocks();
}
