#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include <SDL2/SDL.h>

#include "io.hpp"
#include "window.hpp"
#include "render.hpp"


class Engine {
public:
    Window *window;
    Render *render;
    Mouse *mouse;
    Keyboard *keyboard;

    Engine();

    void loop();

    ~Engine();
};

#endif
