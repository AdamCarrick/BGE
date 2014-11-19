#pragma once
#include "GameComponent.h"

namespace BGE {
	class Steerable2DController :
		public GameComponent
	{
	public:
		Steerable2DController();
		bool Initialise();
		void Update();
		~Steerable2DController();
	};
}
