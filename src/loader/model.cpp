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

	materialsSetup(scene);
	materialsStorage();
	materialsData();

}

Model::~Model() {
}

void Model::meshesSetup(const aiScene* scene) {
	Mesh* mesh;
	for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
		mesh = new Mesh(scene->mMeshes[i]);
		meshes.push_back(mesh);
	}
}

void Model::materialsSetup(const aiScene* scene) {
	for (unsigned int i = 0; i < scene->mNumMaterials; i++) {
		Material material;
		aiColor3D diffuse;
		scene->mMaterials[i]->Get(AI_MATKEY_COLOR_DIFFUSE, diffuse);
		material.diffuse = glm::vec4(diffuse.r, diffuse.g, diffuse.b, 1.0);
		materials.push_back(material);
	}
}

void Model::materialsStorage() {
	glCreateBuffers(1, &materialsSSDO);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, materialsSSDO);

	glNamedBufferStorage(materialsSSDO, materials.size() * sizeof(Material), NULL, GL_DYNAMIC_STORAGE_BIT);
}

void Model::materialsData() {
	for (unsigned int i = 0; i < materials.size(); i++) {
		glNamedBufferSubData(materialsSSDO, i * sizeof(Material), sizeof(Material), &(materials[i]));
	}
}

void Model::draw(ShaderProgram* shaderProgram) {
	std::vector<Mesh*>::iterator iter;
	for (iter = meshes.begin(); iter != meshes.end(); iter++) {
		(*iter)->draw(shaderProgram);
	}
}
