#include "GUI.h"
#include <GL/glew.h>
#include <iostream>

namespace zengine
{
    void GUI::onInitialize()
    {
        if(TTF_Init() == -1)
			std::cerr << "TTF Init failed" << std::endl;

        //load font used for the UI
		m_font = TTF_OpenFont("../assets/fonts/arial.ttf", 24);

        //got the font from here:
        //https://www.quantumenterprises.co.uk/handwriting-fonts/fontvault.htm
    }

    void GUI::onTick()
    {
        
    }

    void GUI::onDisplay()
    {
        glDisable(GL_DEPTH_TEST); 
		glEnable(GL_BLEND); //allows for a bit of transparency with the UI element
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        for (const auto& element : m_elements)
        {
            renderElement(element);
        }

        glEnable(GL_DEPTH_TEST); 
    }

    void GUI::addElement(const GUIElement& element)
    {
        m_elements.push_back(element); //add GUI element 
    }

    void GUI::renderElement(const GUIElement& element)
    {
        glBegin(GL_QUADS);
        glColor4f(element.m_colour.r, element.m_colour.g, element.m_colour.b, element.m_colour.a);
        glVertex2f(element.m_position.x, element.m_position.y);
        glVertex2f(element.m_position.x + element.m_size.x, element.m_position.y);
        glVertex2f(element.m_position.x + element.m_size.x, element.m_position.y + element.m_size.y);
        glVertex2f(element.m_position.x, element.m_position.y + element.m_size.y);
        glEnd();

        //render the text, is there is any...
        if (!element.m_text.empty())
        {
            renderText(element.m_text, element.m_position.x, element.m_position.y);
        }
    }

    //https://learnopengl.com/In-Practice/Text-Rendering
    //https://github.com/libsdl-org/SDL_ttf/releases
    //rendering text with openGL and SDL_TTF (doesnt work :( )
	void GUI::renderText(const std::string& text, float x, float y)
	{
        if (!m_font) return;

		SDL_Color textCol = { 255, 255, 255, 255 };
		SDL_Surface* surface = TTF_RenderText_Blended(m_font, text.c_str(), textCol);

        GLuint tex;
		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, surface->pixels);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(x, y);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(x + surface->w, y);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(x + surface->w, y + surface->h);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(x, y + surface->h);
		glEnd();

		glDisable(GL_TEXTURE_2D);

		glDeleteTextures(1, &tex);
		SDL_FreeSurface(surface);   
	}

	GUI::~GUI()
	{
		TTF_CloseFont(m_font);
		TTF_Quit();
	}
}
