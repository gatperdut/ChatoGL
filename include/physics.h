#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <bullet/btBulletDynamicsCommon.h>

class Physics {
private:
	btBroadphaseInterface* broadphase;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;

public:
	Physics();
	~Physics();

	btDiscreteDynamicsWorld* dynamicsWorld;
};

#endif
