#pragma once
#include <SDL2/SDL.h>
#include <string>

namespace zengine
{
    class Window
    {
    public:
        Window(const std::string& title, int width, int height, bool resizable = true);
        ~Window();

        void swapBuffers();
        SDL_Window* getWindow() const;
        int getWidth() const;
        int getHeight() const;

    private:
        SDL_Window* m_window;
        SDL_GLContext m_glContext;
        int m_width;
        int m_height;
    };
}
