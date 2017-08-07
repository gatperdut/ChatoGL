#ifndef WINDOW_H
#define WINDOW_H

// GLFW
#include <GLFW/glfw3.h>

void debugCallback(GLuint source, GLuint type, GLuint id, GLuint severity, GLint length, const GLchar* message, const void* param);

GLint init(GLFWwindow** window, int* w, int* h);

void clear();

void swap(GLFWwindow** window);

void shutdown();

#endif