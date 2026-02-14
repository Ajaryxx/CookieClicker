#pragma once
#include "Core/Scene.hpp"

namespace CC
{
	namespace Game
	{
		class CCMainScene : public Scene
		{
		public:
			CCMainScene() : Scene("CCMainScene") {}
			~CCMainScene() = default;

		private:

			// Inherited via Scene
			void OnStart() override;
			void OnUpdate(float deltaTime) override;
			void OnDestroy() override;
		};
	}
}