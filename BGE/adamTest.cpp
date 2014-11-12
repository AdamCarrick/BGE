#include "adamTest.h"
#include "PhysicsController.h"
#include "Sphere.h"
#include "PhysicsCamera.h"
#include "Box.h"
#include "Cylinder.h"
#include "Steerable3DController.h"
#include "Ground.h"
#include "Content.h"
#include <btBulletDynamicsCommon.h>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>
#include <gtx/euler_angles.hpp>
#include <gtx/norm.hpp>
#include "VectorDrawer.h"
#include "Utils.h"

using namespace BGE;

adamTest::adamTest(void)
{
}

adamTest::~adamTest(void)
{
}

shared_ptr<PhysicsController> aCyl;
std::shared_ptr<GameComponent> aStation;

bool adamTest::Initialise()
{
	physicsFactory->CreateGroundPhysics();
	physicsFactory->CreateCameraPhysics();

	setGravity(glm::vec3(0, -9, 0));

	shared_ptr<PhysicsController> box1;
	shared_ptr<PhysicsController> box2;

		for (int i = 0; i <10; i++){
			
			for (int j = 0; j < 10;j++)
			{
				box1 = physicsFactory->CreateBox(1, 1, 4, glm::vec3(5, (i*1.2), ((0 + (j * 5)) + ((i%2)*2)) ), glm::quat());
			}
		}
		

	

	if (!Game::Initialise()) {
		return false;
	}



	return true;
}

void BGE::adamTest::Update()
{
	//aCyl->rigidBody->applyTorque(GLToBtVector(glm::vec3(0.0f, 0.0f, 1.0f)));

	Game::Update();
}

void BGE::adamTest::Cleanup()
{
	Game::Cleanup();
}

