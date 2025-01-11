#include <rend/rend.h>
#include "Component.h"

namespace zengine
{
	struct BoxCollider : Component
	{
		bool colliding(const BoxCollider& _other);
	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;
	};

}