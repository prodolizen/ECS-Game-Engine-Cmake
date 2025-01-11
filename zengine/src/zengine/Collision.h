#pragma once
#include <rend/rend.h>
#include "Component.h"
#include <vector>

namespace zengine
{
	struct BoxCollider : Component
	{
		bool colliding(const BoxCollider& _other);
		void setSize(glm::vec3 _size);
	private:
		glm::vec3 m_size;
		glm::vec3 m_offset;
	};

	struct RigidBody : Component
	{
		void onTick();
	private:
		std::vector<std::shared_ptr<BoxCollider>> m_colliders;
	};

}