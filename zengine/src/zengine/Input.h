#pragma once
#include <rend/rend.h>
#include <SDL2/SDL.h>
#include "Component.h"
#include "GUI.h"

namespace zengine
{
    struct Transform;
    struct Input : Component
    {
        glm::vec3 Movement(const SDL_Event& evt);
        glm::vec3 Rotation(const SDL_Event& evt);
        void RecievePosition(glm::vec3 position);
        void RecieveRotation(glm::vec3 rotation);

    private:
        glm::vec3 m_position{ 0,-1,-2 };
        glm::vec3 m_rotation;
        friend struct zengine::Transform;
		float mouseSensitivity = 0.1f;
    };
}
