#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include <algorithm>

#include <SDL2/SDL.h>

#include "color.hpp"
#include "render.hpp"
#include "math/vector.hpp"


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


class Triangle: public AbstractPrimitive {
public:
    Triangle(Render *render): AbstractPrimitive(render) {}

    void draw(Vector&, Vector&, Vector&);
};

#endif
