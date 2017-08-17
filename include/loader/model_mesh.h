#ifndef MODEL_MESH_H
#define MODEL_MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <vector>

#include "loader/vertex.h"
#include "loader/material.h"
#include "shader/shader_program.h"

class ModelMesh {
private:
	glm::vec3* modelPos;

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	aiMesh* mMesh;
	aiMaterial* mMaterial;
	GLuint materialUBO;
	Material material;

	void verticesSetup();

	void fillVertices();
	void fillIndices();
	void materialSetup();

	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;


public:
	ModelMesh(aiMesh* mMesh, aiMaterial* mMaterial);
	~ModelMesh();

	void draw(ShaderProgram* shaderProgram);

};

#endif
