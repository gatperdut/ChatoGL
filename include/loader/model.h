#ifndef MODEL_H_
#define MODEL_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "loader/mesh.h"
#include "loader/material.h"
#include "shader/shader_program.h"

class Model {
private:
	std::vector<Mesh*> meshes;

	glm::vec3 pos;

	GLuint materialsSSDO;

	void meshesSetup(const aiScene* scene);

	std::vector<Material> materials;

public:
	Model(std::string path, glm::vec3 pos);
	~Model();

	void draw(ShaderProgram* shaderProgram);
};



#endif
