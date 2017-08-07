#ifndef LOOP_H
#define LOOP_H

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

// Custom
#include "keyboard.h"
#include "mouse.h"

void loop(GLFWwindow** window, Keyboard* keyboard, Mouse* mouse);

#endif