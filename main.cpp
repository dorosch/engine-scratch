#include <SDL2/SDL.h>

#include "engine.hpp"
#include "model.hpp"
#include "primitive.hpp"


void press(SDL_Event &event) {
    switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            std::cout << "left" << std::endl;
            break;
        case SDLK_RIGHT:
            std::cout << "right" << std::endl;
            break;
        case SDLK_UP:
            std::cout << "up" << std::endl;
            break;
        case SDLK_DOWN:
            std::cout << "down" << std::endl;
            break;
    }
}


void move(SDL_Event &event) {
    std::cout <<
        "x: " << event.motion.x << "; " <<
        "y: " << event.motion.y << std::endl;
}


int main() {
    Engine *engine = new Engine();
    Point point(engine->render);
    Line line(engine->render);

    void (*function_move)(SDL_Event &) = move;
    void (*function_press)(SDL_Event &) = press;
    engine->mouse->move(function_move);
    engine->keyboard->press(function_press);

    Model deer("data/models/deer.obj");
    deer.load();

    engine->render->clear();

    for (auto triangle : deer.facets) {
        line.draw(triangle.v0.x, triangle.v0.y, triangle.v1.x, triangle.v1.y);
        line.draw(triangle.v1.x, triangle.v1.y, triangle.v2.x, triangle.v2.y);
        line.draw(triangle.v2.x, triangle.v2.y, triangle.v0.x, triangle.v0.y);
    }

    engine->render->flush();

    engine->loop();

    delete engine;

    return 0;
}
