#include <SDL2/SDL.h>

#include "engine.hpp"
#include "model.hpp"
#include "math.hpp"
#include "primitive.hpp"


Engine *engine = new Engine();
Point point(engine->render);
Line line(engine->render);
Model deer("data/models/deer.obj");


void draw() {
    engine->render->clear();

    for (auto triangle : deer.facets) {
        line.draw(triangle.v0.x, triangle.v0.y, triangle.v1.x, triangle.v1.y);
        line.draw(triangle.v1.x, triangle.v1.y, triangle.v2.x, triangle.v2.y);
        line.draw(triangle.v2.x, triangle.v2.y, triangle.v0.x, triangle.v0.y);
    }

    engine->render->flush();
}


void up() {
    for (Triangle &triangle : deer.facets) {
        triangle.v0.y += 10;
        triangle.v1.y += 10;
        triangle.v2.y += 10;
    }

    draw();
}


void down() {
    for (Triangle &triangle : deer.facets) {
        triangle.v0.y -= 10;
        triangle.v1.y -= 10;
        triangle.v2.y -= 10;
    }

    draw();
}


void left() {
    for (Triangle &triangle : deer.facets) {
        triangle.v0.x += 10;
        triangle.v1.x += 10;
        triangle.v2.x += 10;
    }

    draw();
}


void right() {
    for (Triangle &triangle : deer.facets) {
        triangle.v0.x -= 10;
        triangle.v1.x -= 10;
        triangle.v2.x -= 10;
    }

    draw();
}


void press(SDL_Event &event) {
    switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            std::cout << "left" << std::endl;
            left();
            break;
        case SDLK_RIGHT:
            std::cout << "right" << std::endl;
            right();
            break;
        case SDLK_UP:
            std::cout << "up" << std::endl;
            up();
            break;
        case SDLK_DOWN:
            std::cout << "down" << std::endl;
            down();
            break;
    }
}


void move(SDL_Event &event) {
    std::cout <<
        "x: " << event.motion.x << "; " <<
        "y: " << event.motion.y << std::endl;
}


int main() {

    void (*function_move)(SDL_Event &) = move;
    void (*function_press)(SDL_Event &) = press;
    engine->mouse->move(function_move);
    engine->keyboard->press(function_press);

    deer.load();

    draw();

    engine->loop();

    delete engine;

    return 0;
}
