#include "render.hpp"


Render::Render(Window *window) {
    Render::object = SDL_CreateRenderer(
        window->object,
        Render::RENDERING_DRIVER_INDEX,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (Render::object == NULL) {
        std::cout << "Error creating render" << std::endl;
    }
}


void Render::clear(SDL_Color color) {
    SDL_SetRenderDrawColor(
        Render::object, color.r, color.g, color.b, color.a
    );
    SDL_RenderClear(Render::object);
}


void Render::draw(int x, int y, SDL_Color color) {
    SDL_SetRenderDrawColor(
        Render::object, color.r, color.g, color.b, color.a
    );
    SDL_RenderDrawPoint(Render::object, x, y);
}


void Render::flush() {
    SDL_RenderPresent(Render::object);
}


Render::~Render() {
    SDL_DestroyRenderer(Render::object);
}
