#include "Entity.h"
#include "Component.h"

namespace zengine
{
	void Entity::tick()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->tick(); //run the tick function for each component attatched to the entity
		}
	}

	void Entity::display()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->display(); //run the display function for each component attatched to the entity
		}
	}

	void Entity::kill()
	{
		if (!m_alive) return;
		m_alive = false;
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->kill(); //run the kill function for each component attatched to the entity
		}
	}

	std::shared_ptr<Core> Entity::getCore()
	{
		return m_core.lock();
	}

	std::shared_ptr<Transform> Entity::getTransform()
	{
		return m_transform.lock();
	}

	std::shared_ptr<Input> Entity::getInput()
	{
		return m_input.lock();
	}
}