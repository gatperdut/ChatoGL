#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "loader/mesh.h"

Mesh::Mesh(aiMesh* mMesh) {
	this->mMesh = mMesh;

	fillVertices();
	fillIndices();

	setup();
}

Mesh::~Mesh() {
}

void Mesh::fillVertices() {
	aiVector3D mVertex;
	aiVector3D mNormal;

	glm::vec3 pos;
	glm::vec3 normal;

	for (unsigned int i = 0; i < mMesh->mNumVertices; i++) {
		Vertex vertex;

		mVertex = mMesh->mVertices[i];
		pos.x = mVertex.x;
		pos.y = mVertex.y;
		pos.z = mVertex.z;

		mNormal = mMesh->mNormals[i];
		normal.x = mNormal.x;
		normal.y = mNormal.y;
		normal.z = mNormal.z;

		vertex.pos = pos;
		vertex.normal = normal;

		vertices.push_back(vertex);
	}
}

void Mesh::fillIndices() {
	aiFace mFace;
	for (unsigned int i = 0; i < mMesh->mNumFaces; i++) {
		mFace = mMesh->mFaces[i];
		for (unsigned int j = 0; j < mFace.mNumIndices; j++) {
			indices.push_back(mFace.mIndices[j]);
		}
	}
}

void Mesh::setup() {
	glCreateVertexArrays(1, &VAO);
	glCreateBuffers(1, &VBO);
	glCreateBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glNamedBufferStorage(VBO, vertices.size() * sizeof(Vertex), &vertices[0], GL_DYNAMIC_STORAGE_BIT);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glNamedBufferStorage(EBO, indices.size() * sizeof(unsigned int), &indices[0], GL_DYNAMIC_STORAGE_BIT);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, normal));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Mesh::draw(ShaderProgram* shaderProgram) {
	glBindVertexArray(VAO);

	glm::mat4 modelMatrix;
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram->id, "model"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// not needed for shadow shader
	glUniform1i(glGetUniformLocation(shaderProgram->id, "materialIndex"), mMesh->mMaterialIndex);

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
