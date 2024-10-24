#include "Core.h"
#include "Entity.h"
#include <iostream>
namespace myengine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;
		//rtn->m_nativeWindow = SDL_CreateWindow(...);
		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->m_core = m_self;
		rtn->m_self = rtn;
		m_entities.push_back(rtn);
		return rtn;
	}

	void Core::start()
	{
		//m_running = true;
		//while (m_running)
		//{
			// SDL stuff
			// Call tick on all entities
			// Call display on all entities
			// Remove "killed" entities
		//}

		for (size_t i = 0; i < 25; i++)
		{
			for (size_t ei = 0; ei < m_entities.size(); ei++)
			{
				m_entities.at(ei)->tick();
			}
			std::cout << i << std::endl;

			for (size_t ei = 0; ei < m_entities.size(); ei++)
			{
				if (!m_entities.at(ei)->m_alive)
				{
					m_entities.erase(m_entities.begin() + ei);
					--ei;
				}
			}
		}
	}
	void Core::stop()
	{
		m_running = false;
	}
}