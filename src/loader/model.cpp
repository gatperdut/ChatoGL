#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "loader/model.h"

Model::Model(std::string path, btRigidBody* rigidBody) {
	this->pos = pos;
	this->rigidBody = rigidBody;
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
	glm::mat4 modelMatrix;
	btTransform transform;
	rigidBody->getMotionState()->getWorldTransform(transform);
	btVector3 translation = transform.getOrigin();
	btQuaternion rotation = transform.getRotation();

	modelMatrix = glm::translate(modelMatrix, glm::vec3(translation.getX(), translation.getY(), translation.getZ()));
	if (rotation.getAngle() != 0) {
		modelMatrix = glm::rotate(modelMatrix, rotation.getAngle(), glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ()));
	}

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "model"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

	std::vector<Mesh*>::iterator iter;
	for (iter = meshes.begin(); iter != meshes.end(); iter++) {
		(*iter)->draw(shaderProgram);
	}
}
