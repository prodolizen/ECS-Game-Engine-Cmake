#pragma once

#include <memory>

namespace zengine
{
	struct Entity;

	struct Component
	{
		std::shared_ptr<Entity> getEntity() const;
	private:
		friend struct zengine::Entity;
		virtual void onTick();
		virtual void onDisplay();
		virtual void onInitialize();
		std::weak_ptr<Entity> m_entity;
		void tick();
		//void kill();
		void display();
	};
}
