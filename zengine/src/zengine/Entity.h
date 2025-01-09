#include <vector>
#include <memory>
namespace zengine
{
	struct Core;
	struct Component;
	struct Transform;
	struct Input;

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

		template <typename T>
		std::shared_ptr<T> get_component()
		{
			for (size_t ci = 0; ci < m_components.size(); ++ci)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(m_components.at(ci));

				if (rtn) return rtn;
			}
		}

		std::shared_ptr<Transform> getTransform();
		std::shared_ptr<Core> core();
		std::shared_ptr<Input> getInput();

	private:

		friend struct zengine::Core; //allows private access

		void tick();
		void display();
		bool m_alive = false;
		std::vector<std::shared_ptr<Component>> m_components;
		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
		std::weak_ptr<Transform> m_transform;
		std::weak_ptr<Input> m_input;
	};
}