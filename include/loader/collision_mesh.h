#ifndef COLLISION_MESH_H
#define COLLISION_MESH_H

#include <bullet/btBulletDynamicsCommon.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class CollisionMesh {
private:
	btConvexHullShape* shape;
	btDefaultMotionState* motionState;
	btScalar mass;
	btVector3 inertia;

public:
	CollisionMesh(aiMesh* mMesh, btVector3 pos, btScalar mass);
	~CollisionMesh();

	btRigidBody* rigidBody;
};

#endif
