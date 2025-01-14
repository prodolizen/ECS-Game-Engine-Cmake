#include "GUI.h"
#include "Core.h"
#include "Entity.h"
#include <stdexcept>

namespace zengine
{
	void GUI::draw(glm::vec2 _size, glm::vec2 _pos)
	{
		SDL_Rect rect = { static_cast<int>(_pos.x), static_cast<int>(_pos.y), static_cast<int>(_size.x), static_cast<int>(_size.y) };
		m_rects.push_back(rect); // Add to vector

		SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(m_renderer, &rect);
		// Remove SDL_RenderPresent(m_renderer);
	}

	void GUI::onInitialize()
	{
		auto core = getEntity()->getCore();
		m_window = core->getWindow();
		m_renderer = SDL_CreateRenderer(m_window->getSDLWindow(), -1, SDL_RENDERER_ACCELERATED);

		if (!m_renderer)
			throw std::runtime_error("failed to create sdl renderer");
	}
}