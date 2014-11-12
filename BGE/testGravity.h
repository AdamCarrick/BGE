#pragma once
#include "Game.h"
#include "GameComponent.h"

namespace BGE {

	class testGravity :
		public GameComponent
	{
	public:
		testGravity();
		~testGravity();
		void update();
	};
}
