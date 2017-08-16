#ifndef POPUP_H
#define POPUP_H

#include "camera.h"
#include "skybox.h"
#include "drawer.h"
#include "physics.h"

extern cam::Camera* camera;

extern Skybox* skybox;

extern Drawer* drawer;

extern Physics* physics;

int main();

#endif
