#ifndef MESH_H_
#define MESH_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <vector>

#include "loader/vertex.h"
#include "loader/material.h"
#include "shader/shader_program.h"

class Mesh {
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
	Mesh(aiMesh* mMesh, aiMaterial* mMaterial, glm::vec3* modelPos);
	~Mesh();

	void draw(ShaderProgram* shaderProgram);

};

#endif
