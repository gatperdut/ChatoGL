#include "loader/collision_mesh.h"
#include "popup.h"

CollisionMesh::CollisionMesh(aiMesh* mMesh, btVector3 pos, btScalar mass) {
	this->mass = mass;

	std::vector<btScalar> vs;
	aiFace mFace;
	for (unsigned int i = 0; i < mMesh->mNumFaces; i++) {
		mFace = mMesh->mFaces[i];
		for (unsigned int j = 0; j < 3; j++) {
			vs.push_back(mMesh->mVertices[mFace.mIndices[j]].x);
			vs.push_back(mMesh->mVertices[mFace.mIndices[j]].y);
			vs.push_back(mMesh->mVertices[mFace.mIndices[j]].z);
		}
	}

	shape = new btConvexHullShape(vs.data(), vs.size() / 3, 3 * sizeof(btScalar));
	motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), pos));
	inertia = btVector3(0, 0, 0);
	shape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, motionState, shape, inertia);
	rigidBody = new btRigidBody(fallRigidBodyCI);
	physics->dynamicsWorld->addRigidBody(rigidBody);
}

CollisionMesh::~CollisionMesh() {
  physics->dynamicsWorld->removeRigidBody(rigidBody);
  delete rigidBody->getMotionState();
  delete rigidBody;
  delete shape;
}
