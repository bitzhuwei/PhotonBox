#ifndef PHYSICS_H
#define PHYSICS_H

class Collider;
class Rigidbody;
class Entity;

#include <vector>
#include <map>

#include "PxPhysicsAPI.h"

using namespace physx;

class Physics
{
public:
	//static void addToPhysicsList(Collider *collider);
	//static void addToPhysicsList(Rigidbody *rigidbody);
	//static void removeFromPhysicsList(Collider* collider);
	//static void removeFromPhysicsList(Rigidbody *rigidbody);

	static void registerObject(Rigidbody* entity);
	static void removePhysicsObject(Rigidbody* rigidbody);
	//static void printList();
	//static std::string getList();

	void init();
	void start();
	void update(double elapsedTime);
	void refeed();
	void reset();
	void destroy();
private:
	//static std::vector<Collider*> _colliders;
	//static std::vector<Rigidbody*> _rigidbodies;
	static std::map<Transform*, PxRigidDynamic*> _physXMap;
	static std::vector<Rigidbody*> _initializationList;

	PxDefaultAllocator		_gAllocator;
	PxDefaultErrorCallback	_gErrorCallback;
	PxFoundation*			_gFoundation;
	PxDefaultCpuDispatcher*	_gDispatcher;
	static PxPvd*			_gPvd;
	static PxPvdTransport*	_gTransport;

	static PxPhysics*		_gPhysics;
	static PxScene*			_gScene;
	static PxMaterial*		_gMaterial;
	static PxSceneDesc*		_sceneDesc;
	
	void addPhysicsObject(Rigidbody* rigidbody); // , Collider* collider);
};

#endif // PHYSICS_H