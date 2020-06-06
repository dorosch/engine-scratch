#ifndef __IO_HPP__
#define __IO_HPP__

#include <SDL2/SDL.h>


class Keyboard {
/**
 * Simple keyboard callback registration class
 */

private:
    void (*_callback_press)(SDL_Event &);

public:
    void press(void (*)(SDL_Event &));

    void event(SDL_Event &);
};


class Mouse {
/**
 * Simple mouse callback registration class
 */

private:
    void (*_callback_move)(SDL_Event &);
    void (*_callback_press)(SDL_Event &);

public:
    void move(void (*)(SDL_Event &));

    void press(void (*)(SDL_Event &));

    void event_move(SDL_Event &);

    void event_press(SDL_Event &);
};

#endif
