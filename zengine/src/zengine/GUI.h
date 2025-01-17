#pragma once
#include "Component.h"
#include <vector>
#include <rend/rend.h>
#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_TTF/SDL_ttf.h>//true type font for the text rendering



//had to switch to using openGL for the GUI as using SDL2 was conflicting with the openGL rendering process ;(
namespace zengine
{
    struct GUIElement
    {
        glm::vec2 m_position;
        glm::vec2 m_size;
        glm::vec4 m_colour;
        std::string m_name;
        std::string m_text;

		GUIElement(glm::vec2 pos, glm::vec2 sz, glm::vec4 col, const std::string& name, const std::string& txt = "") //inline function to define all necessary variables for a GUI element
            : m_position(pos), m_size(sz), m_colour(col), m_name(name), m_text(txt) {}
    };

    struct GUI : Component
    {
        void onInitialize();
        void onTick();
        void onDisplay();

        void addElement(const GUIElement& element);
        ~GUI();

    private:
        std::vector<GUIElement> m_elements;
		TTF_Font* m_font = nullptr;
        void renderElement(const GUIElement& element);
       void renderText(const std::string& text, float x, float y);

    };
}
