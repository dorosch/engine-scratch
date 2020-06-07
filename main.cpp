#include <SDL2/SDL.h>

#include "engine.hpp"
#include "model.hpp"
#include "primitive.hpp"
#include "math/vector.hpp"


Engine *engine = new Engine();
Line line(engine->render);
Model deer("data/models/deer.obj");
const int move_speed = 10;


void draw() {
    engine->render->clear();

    Triangle triangle(engine->render);

    for (int index = 0; index < deer.facets.size(); index += 3) {
        triangle.draw(
            deer.facets[index], deer.facets[index + 1], deer.facets[index + 2]
        );
    }

    engine->render->flush();
}


void up() {
    for (Vector &v : deer.facets) {
        v.y += move_speed;
    }

    draw();
}


void down() {
    for (Vector &v : deer.facets) {
        v.y -= move_speed;
    }

    draw();
}


void left() {
    for (Vector &v : deer.facets) {
        v.x += move_speed;
    }

    draw();
}


void right() {
    for (Vector &v : deer.facets) {
        v.x -= move_speed;
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
