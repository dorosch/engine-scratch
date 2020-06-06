#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>

#include <SDL2/SDL.h>


class Window {
/**
 * A primitive class that implements the functionality
 * of creating and deleting a window in a simple way
 */

public:
    SDL_Window *object;

    const int WIDTH = 800;
    const int HEIGHT = 800;
    const int POSITION_X = 100;
    const int POSITION_Y = 100;
    const char *TITLE = "Engine from scratch";

    Window();

    ~Window();
};

#endif
