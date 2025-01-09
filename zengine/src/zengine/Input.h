#include <rend/rend.h>
#include <SDL2/SDL.h>
#include "Component.h"

namespace zengine
{
	struct Transform;
	struct Input : Component
	{
		glm::vec3 Movement(const SDL_Event& evt);
		glm::vec3 Rotation();
		void RecievePosition(glm::vec3 position);

	private:
		glm::vec3 m_position{ 0,-1,-2 };
		glm::vec3 m_rotation;
		friend struct zengine::Transform;
	};
}