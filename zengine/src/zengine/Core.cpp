#include "Core.h"
#include "Entity.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <rend/rend.h>
#include "Resources.h"
#include "Transform.h"
#include "Input.h"
#include "Player.h"
#include "GUI.h"

namespace zengine
{
    std::shared_ptr<Core> Core::initialize()
    {
        std::shared_ptr<Core> rtn = std::make_shared<Core>();
        rtn->m_window = std::make_shared<Window>("ZEngine Window", 800, 600);
        rtn->m_resources = std::make_shared<Resources>();
        rtn->m_self = rtn;
        return rtn;
    }

    std::shared_ptr<Entity> Core::addEntity()
    {
        std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
        rtn->m_core = m_self;
        rtn->m_self = rtn;
        rtn->m_transform = rtn->addComponent<Transform>();
        rtn->m_input = rtn->addComponent<Input>();
        rtn->m_alive = true;
        m_entities.push_back(rtn);
        return rtn;
    }

    void Core::start()
    {
        m_running = true;

        int playerIndex = -1;

        for (size_t ei = 0; ei < m_entities.size(); ++ei)
        {
            if (m_entities[ei]->getComponent<Player>())
            {
                playerIndex = ei;
                break;
            }
        }

        if (playerIndex >= 0)
        {
            auto playerInput = m_entities[playerIndex]->getInput();
            playerInput->RecievePosition(m_entities[playerIndex]->getTransform()->getPosition());
            playerInput->RecieveRotation(m_entities[playerIndex]->getTransform()->getRotation());
        }

        while (m_running)
        {
            SDL_Event event = {};
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    m_running = false;
                }

                if (playerIndex >= 0)
                {
                    auto playerInput = m_entities[playerIndex]->getInput();
                    glm::vec3 pos = playerInput->Movement(event);
                    glm::vec3 rot = playerInput->Rotation(event);
                    m_entities[playerIndex]->getTransform()->setPosition(pos);
                    m_entities[playerIndex]->getTransform()->setRotation(rot);
                }

                // Handle GUI input
                for (const auto& entity : m_entities)
                {
                    auto gui = entity->getComponent<GUI>();
                    if (gui)
                    {
                        entity->getInput()->HandleGUIInput(event, gui);
                    }
                }
            }

            for (size_t ei = 0; ei < m_entities.size(); ei++)
            {
                m_entities.at(ei)->tick();
            }

            glClearColor(0, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            for (size_t ei = 0; ei < m_entities.size(); ei++)
            {
                m_entities.at(ei)->display();
            }

            m_window->swapBuffers();

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

    std::shared_ptr<Resources> Core::getResources() const
    {
        return m_resources;
    }

    std::shared_ptr<Window> Core::getWindow() const
    {
        return m_window;
    }
}
