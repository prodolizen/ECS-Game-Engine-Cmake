#pragma once
#include "Component.h"
#include <vector>
#include <rend/rend.h>
#include <memory>
#include <string>

namespace zengine
{
    struct GUIElement
    {
        glm::vec2 position;
        glm::vec2 size;
        glm::vec4 color;
        std::string label;
        bool isHovered = false;
        bool isClicked = false;

        GUIElement(glm::vec2 pos, glm::vec2 sz, glm::vec4 col, const std::string& lbl)
            : position(pos), size(sz), color(col), label(lbl) {}
    };

    struct GUI : Component
    {
        void onInitialize() override;
        void onTick() override;
        void onDisplay() override;

        void addElement(const GUIElement& element);
        void updateElementStates(int mouseX, int mouseY, bool mousePressed);

    private:
        std::vector<GUIElement> elements;

        void renderElement(const GUIElement& element);
    };
}
