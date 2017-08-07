#ifndef ERROR_H
#define ERROR_H

#include <iostream>

void _check_gl_error(const char *file, int line);
 
///
/// Usage
/// [... some opengl calls]
/// glCheckError();
///
#define logErr() _check_gl_error(__FILE__,__LINE__)

// GLEW
#include <GL/glew.h>

void debugCallback(GLuint source, GLuint type, GLuint id, GLuint severity, GLint length, const GLchar* message, const void* param);

#endif