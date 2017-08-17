#ifndef MODEL_H_
#define MODEL_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "loader/model_mesh.h"
#include "loader/collision_mesh.h"
#include "loader/material.h"
#include "shader/shader_program.h"

class Model {
private:
	Assimp::Importer importer;

	std::vector<ModelMesh*> modelMeshes;
	CollisionMesh* collisionMesh;

	GLuint materialsSSDO;

	const aiScene* load(std::string path);

	void modelMeshesSetup(std::string modelPath);
	void collisionMeshSetup(std::string collisionPath, btVector3 pos, btScalar mass);

	std::vector<Material> materials;

public:
	Model(std::string modelPath, std::string collisionPath, btVector3 pos, btScalar mass);
	~Model();

	void draw(ShaderProgram* shaderProgram);
};



#endif
