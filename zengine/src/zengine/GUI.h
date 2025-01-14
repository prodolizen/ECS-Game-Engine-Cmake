#include <SDL2/SDL.h>
#include <rend/rend.h>
#include "Texture.h"
#include <vector>
#include "Component.h"
#include "Window.h"

namespace zengine
{
	struct GUI : Component
	{
		void draw(glm::vec2 _size, glm::vec2 _pos);
		void onInitialize();
		SDL_Renderer* m_renderer;
	private:

		std::vector<SDL_Rect> m_rects; //vector containing GUI comps
		std::shared_ptr<Window> m_window;
	};
}