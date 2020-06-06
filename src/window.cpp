#include "window.hpp"


Window::Window() {
    Window::object = SDL_CreateWindow(
        Window::TITLE,
        Window::POSITION_X,
        Window::POSITION_Y,
        Window::WIDTH,
        Window::HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (Window::object == NULL) {
        std::cout << "Error creating window" << std::endl;
    }
}


Window::~Window() {
    SDL_DestroyWindow(Window::object);
}
