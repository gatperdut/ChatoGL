#ifndef MODEL_H_
#define MODEL_H_

#include <GL/glew.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "loader/mesh.h"
#include "loader/material.h"
#include "shader/shader_program.h"

class Model {
private:
	std::vector<Mesh*> meshes;

	GLuint materialsSSDO;

	void meshesSetup(const aiScene* scene);

	void materialsSetup(const aiScene* scene);
	void materialsStorage();
	void materialsData();

	std::vector<Material> materials;

public:
	Model(std::string path);
	~Model();

	void draw(ShaderProgram* shaderProgram);
};



#endif
