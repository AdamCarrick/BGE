#include "adamTest.h"




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
	BGEDebugDrawer *debugDraw;
	debugDraw = new BGEDebugDrawer();
		
	dynamicsWorld->setDebugDrawer(debugDraw);
	int mode = btIDebugDraw::DBG_DrawWireframe
		+ btIDebugDraw::DBG_DrawConstraints
		+ btIDebugDraw::DBG_DrawConstraintLimits;
	dynamicsWorld->getDebugDrawer()->setDebugMode(mode);
	
	//physicsFactory->CreateGroundPhysics();
	physicsFactory->CreateCameraPhysics();

	setGravity(glm::vec3(0, 0, 0));

	shared_ptr<PhysicsController> box1;
	shared_ptr<PhysicsController> box2;

		for (int i = 0; i <10; i++){
			
			for (int j = 0; j < 10;j++)
			{
				//box1 = physicsFactory->CreateBox(1, 1, 4, glm::vec3(5, (i*1.2), ((0 + (j * 5)) + ((i%2)*2)) ), glm::quat());
			}
		}

		makeAnimat(glm::vec3(0,0,0));

		//makeAnimat(glm::vec3(10, 0, 0));

		//makeAnimat(glm::vec3(20, 0, 0));

		//makeAnimat(glm::vec3(30, 0, 0));
		

		

	if (!Game::Initialise()) {
		return false;
	}



	return true;
}

void adamTest::Update()
{
	//aCyl->rigidBody->applyTorque(GLToBtVector(glm::vec3(0.0f, 0.0f, 1.0f)));

	Game::Update();
}

void adamTest::Cleanup()
{
	Game::Cleanup();
}

void adamTest::makeAnimat(glm::vec3 location)
{
	shared_ptr<PhysicsController> leftFrontFoot;
	shared_ptr<PhysicsController> rightFrontFoot;
	shared_ptr<PhysicsController> leftBackFoot;
	shared_ptr<PhysicsController> rightBackFoot;

	leftFrontFoot = physicsFactory->CreateBox(1, 2, 1, location + glm::vec3(0, 1, 5), glm::quat());
	rightFrontFoot = physicsFactory->CreateBox(1, 2, 1, location + glm::vec3(3, 1, 5), glm::quat());

	leftBackFoot = physicsFactory->CreateBox(1, 2, 1, location + glm::vec3(0, 1, 0), glm::quat());
	rightBackFoot = physicsFactory->CreateBox(1, 2, 1, location + glm::vec3(3, 1, 0), glm::quat());

	shared_ptr<PhysicsController> leftFrontShin;
	shared_ptr<PhysicsController> rightFrontShin;
	shared_ptr<PhysicsController> leftBackShin;
	shared_ptr<PhysicsController> rightBackShin;

	leftFrontShin = physicsFactory->CreateBox(1, 2, 1, location + glm::vec3(0, 3.5, 5), glm::quat());
	rightFrontShin = physicsFactory->CreateBox(1, 2, 1, location + glm::vec3(3, 3.5, 5), glm::quat());

	leftBackShin = physicsFactory->CreateBox(1, 2, 1, location + glm::vec3(0, 3.5, 0), glm::quat());
	rightBackShin = physicsFactory->CreateBox(1, 2, 1, location + glm::vec3(3, 3.5, 0), glm::quat());

	shared_ptr<PhysicsController> bodyFront;
	shared_ptr<PhysicsController> bodyBack;

	bodyFront = physicsFactory->CreateBox(1, 1, 2, location + glm::vec3(1.5, 4.5, 4), glm::quat());
	bodyBack = physicsFactory->CreateBox(1, 1, 2, location + glm::vec3(1.5, 4.5, 1), glm::quat());

	btHingeConstraint * hinge = new btHingeConstraint(*leftFrontShin->rigidBody, *leftFrontFoot->rigidBody,
		btVector3(0, -1.25f, 0), btVector3(0, 1.25f, 0) //local point of connection, for item a and b
		, btVector3(1, 0, 0), btVector3(0, 0, 0), false);// the vectors around which to rotate

	dynamicsWorld->addConstraint(hinge);
	hinge->setDbgDrawSize(btScalar(5.0f));
}
