#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include <iostream>

// Standard
#include <vector>
#include <glm/glm.hpp>

// GLEW
#include <GL/glew.h>

// ChatoGL
#include "shader/shader_program.h"

class ShaderManager {
  private:
    ShaderProgram* initCommon(std::string vertex, std::string fragment);
    void initRegular();
    void initSkybox();
    void initShadow();
    void initLamp();

    GLuint renderMatricesUBO;
    void renderMatricesStorage();
    void renderMatricesBind(ShaderProgram* shaderProgram);

    GLuint shadowFramebufferName;
    void shadowFramebufferStorage();

  public:
    ShaderManager();
    ~ShaderManager();
    
    ShaderProgram* regular;
    ShaderProgram* skybox;
    ShaderProgram* shadow;
    ShaderProgram* lamp;
    
    void renderMatrixDataProjection(glm::mat4 projectionMatrix);
    void renderMatrixDataView(glm::mat4 viewMatrix);

    void shadowFramebufferUse();
    void shadowFramebufferRelease();
    void attachShadowTexture2Framebuffer(GLuint shadowTextureName);

    void cameraPositionSet(ShaderProgram* shaderProgram);
};

#endif
