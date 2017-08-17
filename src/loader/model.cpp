#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "loader/model.h"
#include "popup.h"

Model::Model(std::string modelPath, std::string collisionPath, btVector3 pos, btScalar mass) {
	modelMeshesSetup(modelPath);
	collisionMeshSetup(collisionPath, pos, mass);
}

Model::~Model() {
}

const aiScene* Model::load(std::string path) {
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);
	if (!scene || (scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE) || !scene->mRootNode) {
		std::cerr << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
	}
	return scene;
}

void Model::modelMeshesSetup(std::string modelPath) {
	const aiScene* scene = load(modelPath);
	ModelMesh* mesh;
	for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
		mesh = new ModelMesh(scene->mMeshes[i], scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]);
		modelMeshes.push_back(mesh);
	}
}

void Model::collisionMeshSetup(std::string collisionPath, btVector3 pos, btScalar mass) {
	const aiScene* scene = load(collisionPath);
	collisionMesh = new CollisionMesh(scene->mMeshes[0], pos, mass);
}

void Model::draw(ShaderProgram* shaderProgram) {
	glm::mat4 modelMatrix;
	btTransform transform;
	collisionMesh->rigidBody->getMotionState()->getWorldTransform(transform);
	btVector3 translation = transform.getOrigin();
	btQuaternion rotation = transform.getRotation();

	modelMatrix = glm::translate(modelMatrix, glm::vec3(translation.getX(), translation.getY(), translation.getZ()));
	if (rotation.getAngle() != 0) {
		modelMatrix = glm::rotate(modelMatrix, rotation.getAngle(), glm::vec3(rotation.getX(), rotation.getY(), rotation.getZ()));
	}

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "model"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

	std::vector<ModelMesh*>::iterator iter;
	for (iter = modelMeshes.begin(); iter != modelMeshes.end(); iter++) {
		(*iter)->draw(shaderProgram);
	}
}
