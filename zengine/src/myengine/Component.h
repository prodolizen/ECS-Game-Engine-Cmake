#include <memory>

namespace myengine
{
	struct Entity;

	struct Component
	{
	private:
		friend struct myengine::Entity;
		virtual void onTick();
		//virtual void onDisplay();
		virtual void onInitialise();
		std::weak_ptr<Entity> m_entity;
		void tick();
		void kill();
		//void display();
	};
}
