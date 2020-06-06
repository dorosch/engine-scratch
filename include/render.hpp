#ifndef __RENDER_HPP__
#define __RENDER_HPP__

#include <iostream>

#include <SDL2/SDL.h>

#include "color.hpp"
#include "window.hpp"


class Render {
/**
 * A primitive class that implements rendering functionality for
 * the window, such as drawing a single pixel and cleaning the window
 */

public:
    SDL_Renderer *object;
    const int RENDERING_DRIVER_INDEX = -1;

    Render(Window *);

    void clear(SDL_Color color=BLACK);

    void draw(int, int, SDL_Color color=WHITE);

    void flush();

    ~Render();
};

#endif
