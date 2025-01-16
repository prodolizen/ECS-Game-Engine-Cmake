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
        glm::vec2 position;
        glm::vec2 size;
        glm::vec4 color;
        std::string label;
        std::string text;

		GUIElement(glm::vec2 pos, glm::vec2 sz, glm::vec4 col, const std::string& lbl, const std::string& txt = "") //inline function to define all necessary variables for a GUI element
            : position(pos), size(sz), color(col), label(lbl), text(txt) {}
    };

    struct GUI : Component
    {
        void onInitialize();
        void onTick();
        void onDisplay();

        void addElement(const GUIElement& element);
        ~GUI();

    private:
        std::vector<GUIElement> elements;
		TTF_Font* font = nullptr;
        void renderElement(const GUIElement& element);
       void renderText(const std::string& text, float x, float y);

    };
}
