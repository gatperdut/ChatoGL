#include <iostream>

#include "managers/model_manager.h"


ModelManager::ModelManager() {
}

ModelManager::~ModelManager() {
  std::vector<Model*>::iterator iter;
  for (iter = models.begin(); iter != models.end(); iter++) {
    delete *iter;
  }
}

void ModelManager::load(std::string path) {
	Model* model = new Model(path);
  models.push_back(model);
}

void ModelManager::drawAll(ShaderProgram* shaderProgram) {
  std::vector<Model*>::iterator iter;
  for (iter = models.begin(); iter != models.end(); iter++) {
    (*iter)->draw(shaderProgram);
  }
}
