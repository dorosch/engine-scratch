#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include <SDL2/SDL.h>

#include "color.hpp"
#include "render.hpp"


class AbstractPrimitive {
/**
 * Abstract class graphic primitives
 */

public:
    Render *render;

    AbstractPrimitive(Render *);
};


class Point: public AbstractPrimitive {
public:
    Point(Render *render): AbstractPrimitive(render) {}

    void draw(int, int, SDL_Color color=WHITE);
};


class Line: public AbstractPrimitive {
public:
    Line(Render *render): AbstractPrimitive(render) {}

    void draw(int, int, int, int, SDL_Color color=WHITE);
};

#endif
