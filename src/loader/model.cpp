#include <iostream>

#include "loader/model.h"

Model::Model(std::string path) {
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);
	if (!scene || (scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE) || !scene->mRootNode) {
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}
	meshesSetup(scene);

}

Model::~Model() {
}

void Model::meshesSetup(const aiScene* scene) {
	Mesh* mesh;
	for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
		mesh = new Mesh(scene->mMeshes[i], scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]);
		meshes.push_back(mesh);
	}
}

void Model::draw(ShaderProgram* shaderProgram) {
	std::vector<Mesh*>::iterator iter;
	for (iter = meshes.begin(); iter != meshes.end(); iter++) {
		(*iter)->draw(shaderProgram);
	}
}
