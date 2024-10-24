#include "Component.h"

namespace myengine
{
	void Component::onTick(){}
	void Component::onInitialise() {}

	void Component::tick()
	{
		onTick();
	}
	void Component::kill() {}
}