#pragma once
#include "Game.h"
#include "PhysicsController.h"
#include "PhysicsFactory.h"
#include <btBulletDynamicsCommon.h>

namespace BGE
{
	class adamTest :
		public Game
	{
	private:

	public:
		adamTest(void);
		~adamTest(void);
		bool Initialise();
		void Update();
		void Cleanup();
		void CreateWall();
	};
}
