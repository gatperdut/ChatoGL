#ifndef SHADER_H
#define SHADER_H

// Standard
#include <string>

// GLEW
#include <GL/glew.h>

class ShaderObject {
  private:
    void compile();

  public:
    GLuint id;

    ShaderObject(GLenum type, std::string filePath);

    ~ShaderObject();
};



#endif
