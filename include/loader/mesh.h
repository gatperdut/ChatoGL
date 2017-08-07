#ifndef MESH_H_
#define MESH_H_

#include <GL/glew.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <vector>

#include "loader/vertex.h"
#include "shader/shader_program.h"

class Mesh {
private:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	aiMesh* mMesh;

	void fillVertices();
	void fillIndices();

	unsigned int VBO;
	unsigned int EBO;

	void setup();

public:
	Mesh(aiMesh* mMesh);
	~Mesh();

	void draw(ShaderProgram* shaderProgram);

	unsigned int VAO;
};

#endif
