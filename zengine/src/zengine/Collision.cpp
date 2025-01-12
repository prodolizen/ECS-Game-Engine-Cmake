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

		if (a.y > b.y)
		{
			if (b.y + bhs.y < a.y - ahs.y)
			{
				return false;
			}
		}
		else
		{
			if (a.y + ahs.y < b.y - bhs.y)
			{
				return false;
			}
		}

		if (a.z > b.z)
		{
			if (b.z + bhs.z < a.z - ahs.z)
			{
				return false;
			}
		}
		else
		{
			if (a.z + ahs.z < b.z - bhs.z)
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
					m_colliders.at(j)->getEntity()->getComponent<Audio>()->playSound("../assets/sounds/slash.ogg", false);
					m_colliders.at(j)->getEntity()->kill();
					m_colliders.erase(m_colliders.begin() + j);
				}
			}
		}
	}

}