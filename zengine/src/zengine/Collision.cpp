#include "Collision.h"
#include "Transform.h"
#include "Entity.h"
#include "Core.h"
#include <iostream>

namespace zengine
{
	bool BoxCollider::colliding(const BoxCollider& _other)
	{
		glm::vec3 a = getEntity()->getTransform()->getPosition();
		glm::vec3 b = _other.getEntity()->getTransform()->getPosition();
		glm::vec3 ahs = m_size / 2.0f;
		glm::vec3 bhs = _other.m_size / 2.0f;
		if (a.x > b.x)
		{
			if (b.x + bhs.x < a.x - ahs.x)
			{
				return false;
			}
		}
		else
		{
			if (a.x + ahs.x < b.x - bhs.x)
			{
				return false;
			}
		}
		// TODO: y
		// TODO: z

		return true;
	}

	void BoxCollider::setSize(glm::vec3 _size)
	{
		m_size = _size;
	}

	void RigidBody::onTick()
	{
		getEntity()->getCore()->find<BoxCollider>(m_colliders);

		for (int i = 0; i < m_colliders.size(); i++)
		{
			for (int j = i + 1; j < m_colliders.size(); j++)
			{
				if (m_colliders.at(i)->colliding(*m_colliders.at(j)))
				{
					std::cout << "Colliding" << std::endl;
				}
			}
		}
	}

}