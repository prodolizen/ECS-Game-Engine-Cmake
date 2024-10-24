#include <vector>
#include <memory>
namespace zengine
{
	struct Core;
	struct Component;

	struct Entity
	{
		void kill();
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();


			rtn->m_entity = m_self;
			rtn->onInitialize();
			m_components.push_back(rtn);

			return rtn;
		}

	private:

		friend struct zengine::Core; //allows private access

		void tick();
		void display();
		bool m_alive;
		std::vector<std::shared_ptr<Component>> m_components;
		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
	};
}