#include <iostream>

// ChatoGL
#include "managers/shader_manager.h"
#include "managers/managers.h"
#include "popup.h"
#include "error.h"

void ShaderManager::shadowFramebufferStorage() {
  glCreateFramebuffers(1, &shadowFramebufferName);
  glBindFramebuffer(GL_FRAMEBUFFER, shadowFramebufferName);
  glDrawBuffer(GL_NONE);
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ShaderManager::shadowFramebufferUse() {
  glViewport(0, 0, 1024, 1024);
  glBindFramebuffer(GL_FRAMEBUFFER, shadowFramebufferName);
}

void ShaderManager::shadowFramebufferRelease() {
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void ShaderManager::attachShadowTexture2Framebuffer(GLuint shadowTextureName) {
  glNamedFramebufferTexture(shadowFramebufferName, GL_DEPTH_ATTACHMENT, shadowTextureName, 0);
}
