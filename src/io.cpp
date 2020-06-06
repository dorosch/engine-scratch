#include "io.hpp"


void Keyboard::press(void (*function)(SDL_Event &)) {
    Keyboard::_callback_press = function;
}


void Keyboard::event(SDL_Event &event) {
    if (Keyboard::_callback_press != NULL) {
        Keyboard::_callback_press(event);
    }
}


void Mouse::move(void (*function)(SDL_Event &)) {
    Mouse::_callback_move = function;
}


void Mouse::press(void (*function)(SDL_Event &)) {
    Mouse::_callback_press = function;
}


void Mouse::event_move(SDL_Event &event) {
    if (Mouse::_callback_move != NULL) {
        Mouse::_callback_move(event);
    }
}


void Mouse::event_press(SDL_Event &event) {
    if (Mouse::_callback_press != NULL) {
        Mouse::_callback_press(event);
    }
}
