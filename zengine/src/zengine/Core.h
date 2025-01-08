#include <memory>
#include <vector>
#include <string>

namespace zengine
{
	struct Entity;
	struct Resources;

	struct Core
	{
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();
		void start();
		void stop();
		std::shared_ptr<Resources> resourceRef() const;
	private:
		std::vector<std::shared_ptr<Entity> > m_entities;
		bool m_running;
		std::weak_ptr<Core> m_self;
		SDL_Window* m_nativeWindow;
		std::shared_ptr<Resources> m_resources;
	};
}