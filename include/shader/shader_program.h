#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

// Standard
#include <vector>
#include <string>

// GLEW
#include <GL/glew.h>

// ChatoGL
#include "shader/shader_object.h"

class ShaderProgram {
  private:
    std::vector<ShaderObject*> shaderObjects;

  public:
    GLuint id;

    ShaderProgram();

    ~ShaderProgram();

    void attach(GLenum type, std::string filePath);

    void link();

    void use();
};

#endif
