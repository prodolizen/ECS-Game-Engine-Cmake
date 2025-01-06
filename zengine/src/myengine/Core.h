#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include "Resource.h"

namespace zengine
{
	struct Entity;

	struct Core
	{
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();
		void start();
		void stop();
	private:
		std::vector<std::shared_ptr<Entity> > m_entities;
		bool m_running;
		std::weak_ptr<Core> m_self;
		SDL_Window* m_nativeWindow;
	};

	struct Resources
	{
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			// Search for previously loaded resource
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				// Return it if found
				if (m_resources.at(i)->getPath() == _path)
				{
					return m_resources.at(i);
				}
			}
			// Create new instance, construct it and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = _path;
			rtn->load();
			m_resources.push_back(rtn);
			return rtn;
		}
	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
	};
}