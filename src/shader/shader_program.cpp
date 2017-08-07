// Standard
#include <iostream>

// ChatoGL
#include "shader/shader_program.h"

ShaderProgram::ShaderProgram() {
  id = glCreateProgram();
}

ShaderProgram::~ShaderProgram() {
  std::vector<ShaderObject*>::iterator iter;
  for (iter = shaderObjects.begin(); iter != shaderObjects.end(); iter++) {
    delete *iter;
  }
}

void ShaderProgram::attach(GLenum type, std::string filePath) {
  ShaderObject* shaderObject = new ShaderObject(type, filePath);
  glAttachShader(id, shaderObject->id);
  shaderObjects.push_back(shaderObject);
}

void ShaderProgram::link() {
  glLinkProgram(id);

  GLint success;
  glGetProgramiv(id, GL_LINK_STATUS, &success);
  if (!success) {
    GLint length;
    glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
    GLchar infoLog[length];
    glGetProgramInfoLog(id, length, NULL, infoLog);
    std::cerr << "ERROR::SHADERPROGRAM::LINK " << std::endl << infoLog << std::endl;
  }
}

void ShaderProgram::use() {
  glUseProgram(id);
}
