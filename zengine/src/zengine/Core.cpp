#include "Core.h"
#include "Entity.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <rend/rend.h>
#include "Resources.h"

namespace zengine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;
		rtn->m_nativeWindow = SDL_CreateWindow("nativeWindow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		SDL_GL_CreateContext(rtn->m_nativeWindow);
		glewInit();
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
		m_running = true;
		while(m_running)
		{
			SDL_Event event = {};
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					m_running = false;
				}
			}
			for (size_t ei = 0; ei < m_entities.size(); ei++)
			{
				m_entities.at(ei)->tick();
				//SDL_GL_SwapWindow(m_nativeWindow->m_raw);
			
			}

			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (size_t ei = 0; ei < m_entities.size(); ei++)
			{
				m_entities.at(ei)->display();
			}

			// TODO: Create Windows class
			SDL_GL_SwapWindow(m_nativeWindow);

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
	std::shared_ptr<Resources> Core::resourceRef() const
	{
		return m_resources;
	}
}