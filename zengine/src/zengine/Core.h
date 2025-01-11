#pragma once
#include <memory>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include "Collision.h"

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
		std::shared_ptr<Resources> getResources() const;

        template <typename T>
        void find(std::vector<std::shared_ptr<T>>& _out)
        {
            // Go through each Entity in Core.
            for (size_t ei = 0; ei < m_entities.size(); ++ei)
            {
                std::shared_ptr<Entity> e = m_entities.at(ei);
                // Go through each Component in Entity.
                for (size_t ci = 0; ci < e->m_components.size(); ++ci)
                {
                    std::shared_ptr<Component> c = e->m_components.at(ci);
                    // Try to dynamic cast the Component to a T.
                    std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);
                    // If cast succeeds, then check if it already exists in the output array.
                    if (t)
                    {
                        // Check if the component is already in the output vector.
                        auto it = std::find(_out.begin(), _out.end(), t);
                        if (it == _out.end())  // If not found, add it.
                        {
                            _out.push_back(t);
                        }
                    }
                }
            }
        }

	private:
		std::vector<std::shared_ptr<Entity> > m_entities;
		bool m_running = false;
		std::weak_ptr<Core> m_self;
		SDL_Window* m_nativeWindow;
		std::shared_ptr<Resources> m_resources;
		std::vector<std::shared_ptr<BoxCollider>> m_boxColliders;
	};
}