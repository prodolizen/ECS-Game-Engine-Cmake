#include "Input.h"
#include <iostream>
namespace zengine
{
    glm::vec3 Input::Movement(const SDL_Event& evt)
    {
        if (evt.type == SDL_KEYDOWN)
        {
            switch (evt.key.keysym.sym)
            {
            case SDLK_w:
                m_position.z -= 0.1f;
                std::cout << "W" << std::endl;
                break;

            case SDLK_s:
                m_position.z += 0.1f;
                std::cout << "S" << std::endl;
                break;

            case SDLK_a:
                m_position.x -= 0.1f;
                std::cout << "A" << std::endl;
                break;

            case SDLK_d:
                m_position.x += 0.1f;
                std::cout << "D" << std::endl;
                break;
            }
        }

        return m_position;
    };

	glm::vec3 Input::Rotation()
	{
		return m_rotation;
	}
    void Input::RecievePosition(glm::vec3 position)
    {
        m_position = position;
    };
}