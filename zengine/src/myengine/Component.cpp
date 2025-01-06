#include "Component.h"

namespace zengine
{
	void Component::onTick(){}
	void Component::onInitialize() {}
	void Component::onDisplay() {}

	void Component::tick()
	{
		onTick();
	}

	void Component::display ()
	{
		onDisplay();
	}

	void Component::kill() {}

	std::shared_ptr<Entity> Component::entity()
	{
		return m_entity.lock();
	}
}