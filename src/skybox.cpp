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
#include "skybox.h"
#include "managers/managers.h"

Skybox::Skybox() {
  geometry();
  texture();
}

Skybox::~Skybox() {

}

void Skybox::draw() {
  shaderManager->skybox->use();

  glDepthMask(GL_FALSE);

  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);

  glDepthMask(GL_TRUE);
}

void Skybox::geometry() {
  glCreateVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  GLuint VBO;
  glCreateBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glNamedBufferStorage(VBO, sizeof(GLfloat) * 3 * 36, geometryVx, GL_DYNAMIC_STORAGE_BIT);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
  glEnableVertexAttribArray(0);
}

void Skybox::texture() {
  std::vector<std::string> faces = {
    "resource/skybox/ocean/right.jpg",
    "resource/skybox/ocean/left.jpg",
    "resource/skybox/ocean/top.jpg",
    "resource/skybox/ocean/bottom.jpg",
    "resource/skybox/ocean/back.jpg",
    "resource/skybox/ocean/front.jpg"
  };

  glCreateTextures(GL_TEXTURE_CUBE_MAP, 1, &texName);
  glBindTextureUnit(0, texName);
  glTextureStorage2D(texName, 1, GL_RGB8, 2048, 2048);

  unsigned char* image;
  int width, height;
  for (int face = 0; face < 6; face++){
    image = SOIL_load_image(faces[face].c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glTextureSubImage3D(texName, 0, 0, 0, face, 2048, 2048, 1, GL_RGB, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);
  }
}
