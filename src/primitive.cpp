#include "primitive.hpp"


AbstractPrimitive::AbstractPrimitive(Render *render) {
    AbstractPrimitive::render = render;
}


void Point::draw(int x, int y, SDL_Color color) {
    Point::render->draw(x, y, color);
}


void Line::draw(int x0, int y0, int x1, int y1, SDL_Color color) {
    const int dx = abs(x1 - x0);
    const int dy = abs(y1 - y0);
    const int sx = (x0 < x1) ? 1 : -1;
    const int sy = (y0 < y1) ? 1 : -1;
    int error = dx - dy;

    Line::render->draw(x1, y1, color);

    while(x0 != x1 || y0 != y1) {
        int error2 = error * 2;

        Line::render->draw(x0, y0, color);

        if(error2 > -dy) {
            x0 += sx;
            error -= dy;
        }

        if(error2 < dx) {
            y0 += sy;
            error += dx;
        }
    }
}
