#include <memory>
#include <vector>
#include <SDL2/SDL.h>

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
}