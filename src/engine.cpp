#include "engine.hpp"


Engine::Engine() {
    Engine::window = new Window();
    Engine::render = new Render(window);
    Engine::mouse = new Mouse();
    Engine::keyboard = new Keyboard();
}


void Engine::loop() {
    SDL_Event event;

    while (true) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
            else if (event.type == SDL_MOUSEMOTION) {
                Engine::mouse->event_move(event);
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                Engine::mouse->event_press(event);
            }
            else if (
                event.type == SDL_KEYDOWN || event.type == SDL_KEYUP
            ) {
                Engine::keyboard->event(event);
            }
        }
    }
}


Engine::~Engine() {
    delete Engine::window;
    delete Engine::render;
    delete Engine::mouse;
    delete Engine::keyboard;

    SDL_Quit();
}
