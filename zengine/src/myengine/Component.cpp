#include "Component.h"

namespace zengine
{
	void Component::onTick(){}
	void Component::onInitialise() {}

	void Component::tick()
	{
		onTick();
	}
	void Component::kill() {}
}