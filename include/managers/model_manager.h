#ifndef MODEL_MANAGER_H
#define MODEL_MANAGER_H

// Standard
#include <vector>

// GLEW
#include <GL/glew.h>

// ChatoGL
#include "loader/model.h"
#include "shader/shader_program.h"

class ModelManager {
  private:
    std::vector<Model*> models;

  public:
    ModelManager();

    ~ModelManager();

    void load(std::string path);

    void drawAll(ShaderProgram* shaderProgram);
};

#endif
