#include "GUI.h"
#include <GL/glew.h>
#include <iostream>

namespace zengine
{
    void GUI::onInitialize()
    {
        // Initialize any required states or shaders for the GUI
    }

    void GUI::onTick()
    {
        // Handle additional logic here, such as updating element states
    }

    void GUI::onDisplay()
    {
        glDisable(GL_DEPTH_TEST); // Disable depth testing for GUI rendering
        glEnable(GL_BLEND);       // Enable blending for transparency
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        for (const auto& element : elements)
        {
            renderElement(element);
        }

        glEnable(GL_DEPTH_TEST); // Re-enable depth testing after GUI rendering
    }

    void GUI::addElement(const GUIElement& element)
    {
        elements.push_back(element);
    }

    void GUI::updateElementStates(int mouseX, int mouseY, bool mousePressed)
    {
        for (auto& element : elements)
        {
            element.isHovered =
                mouseX >= element.position.x && mouseX <= element.position.x + element.size.x &&
                mouseY >= element.position.y && mouseY <= element.position.y + element.size.y;

            if (element.isHovered && mousePressed)
            {
                element.isClicked = true;
                std::cout << "Clicked on: " << element.label << std::endl;
            }
            else
            {
                element.isClicked = false;
            }
        }
    }

    void GUI::renderElement(const GUIElement& element)
    {
        glBegin(GL_QUADS);
        glColor4f(element.color.r, element.color.g, element.color.b, element.color.a);
        glVertex2f(element.position.x, element.position.y);
        glVertex2f(element.position.x + element.size.x, element.position.y);
        glVertex2f(element.position.x + element.size.x, element.position.y + element.size.y);
        glVertex2f(element.position.x, element.position.y + element.size.y);
        glEnd();
    }
}
