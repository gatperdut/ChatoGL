// ChatoGL
#include "shader/shader_object.h"
#include "reader.h"

ShaderObject::ShaderObject(GLenum type, std::string filePath) {
  bool success;
  std::string text = read(filePath, &success);
  if (!success) {
    return;
  }

  id = glCreateShader(type);

  const GLchar* code = text.c_str();
  glShaderSource(id, 1, &code, NULL);

  compile();
}

ShaderObject::~ShaderObject() {
  glDeleteShader(id);
}

void ShaderObject::compile() {
  glCompileShader(id);

  GLint success;
  glGetShaderiv(id, GL_COMPILE_STATUS, &success);
  if (!success) {
    GLint length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    GLchar infoLog[length];
    glGetShaderInfoLog(id, length, NULL, infoLog);
    std::cerr << "ERROR::SHADEROBJECT::COMPILE " << std::endl << infoLog << std::endl;
  }
}
