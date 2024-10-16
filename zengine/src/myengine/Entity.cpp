#include "Entity.h"
template <typename T>
std::shared_ptr<T> Entity::addComponent()
{
	std::shared_ptr<T> rtn = std::make_shared<T>();
	rtn->m_entity = m_self;
	rtn->initialize();
	m_components.push_back(rtn);
	return rtn;
}

void Entity::tick()
{
	for (size_t ci = 0; ci < m_components.size(); ++ci)
	{
		m_components.at(ci)->tick();
	}
}
// display is almost identical

void Entity::kill()
{
	m_alive = false;
}
void Entity::kill()
{
	if (!m_alive) return;
	m_alive = false;
	for (size_t ci = 0; ci < m_components.size(); ++ci)
	{
		m_components.at(ci)->kill();
	}
}