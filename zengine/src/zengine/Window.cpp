#include "Window.h"
#include <stdexcept>
#include <rend/rend.h>

namespace zengine
{
    Window::Window(const std::string& title, int width, int height, bool resizable)
        : m_window(nullptr), m_glContext(nullptr), m_width(width), m_height(height)
    {
        Uint32 flags = SDL_WINDOW_OPENGL | (resizable ? SDL_WINDOW_RESIZABLE : 0);

        m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if (!m_window)
        {
            throw std::runtime_error("Failed to create SDL window: " + std::string(SDL_GetError()));
        }

        m_glContext = SDL_GL_CreateContext(m_window);
        if (!m_glContext)
        {
            SDL_DestroyWindow(m_window);
            throw std::runtime_error("Failed to create OpenGL context: " + std::string(SDL_GetError()));
        }

        if (glewInit() != GLEW_OK)
        {
            SDL_GL_DeleteContext(m_glContext);
            SDL_DestroyWindow(m_window);
            throw std::runtime_error("Failed to initialize GLEW");
        }

        SDL_GL_SetSwapInterval(1);
    }

    Window::~Window()
    {
        if (m_glContext)
        {
            SDL_GL_DeleteContext(m_glContext);
        }
        if (m_window)
        {
            SDL_DestroyWindow(m_window);
        }
    }

    void Window::swapBuffers()
    {
        SDL_GL_SwapWindow(m_window);
    }

    SDL_Window* Window::getSDLWindow() const
    {
        return m_window;
    }

    int Window::getWidth() const
    {
        return m_width;
    }

    int Window::getHeight() const
    {
        return m_height;
    }
}
