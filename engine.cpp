#include <iostream>

#include <SDL2/SDL.h>


const SDL_Color BLACK = {.r = 0, .g = 0, .b = 0};
const SDL_Color RED = {.r = 255, .g = 0, .b = 0};
const SDL_Color GREEN = {.r = 0, .g = 255, .b = 0};
const SDL_Color BLUE = {.r = 0, .g = 0, .b = 255};
const SDL_Color WHITE = {.r = 255, .g = 255, .b = 255};


class Window {
/**
 * A primitive class that implements the functionality
 * of creating and deleting a window in a simple way
 */

public:
    SDL_Window *object;

    const int WIDTH = 800;
    const int HEIGHT = 800;
    const int POSITION_X = 100;
    const int POSITION_Y = 100;
    const char *TITLE = "Engine from scratch";

    Window() {
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

    ~Window() {
        SDL_DestroyWindow(Window::object);
    }
};


class Render {
/**
 * A primitive class that implements rendering functionality for
 * the window, such as drawing a single pixel and cleaning the window
 */

public:
    SDL_Renderer *object;
    const int RENDERING_DRIVER_INDEX = -1;

    Render(Window *window) {
        Render::object = SDL_CreateRenderer(
            window->object,
            Render::RENDERING_DRIVER_INDEX,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );

        if (Render::object == NULL) {
            std::cout << "Error creating render" << std::endl;
        }
    }

    void clear(SDL_Color color=BLACK) {
        SDL_SetRenderDrawColor(
            Render::object, color.r, color.g, color.b, color.a
        );
        SDL_RenderClear(Render::object);
    }

    void draw(int x, int y, SDL_Color color=WHITE) {
        SDL_SetRenderDrawColor(
            Render::object, color.r, color.g, color.b, color.a
        );
        SDL_RenderDrawPoint(Render::object, x, y);
    }

    void flush() {
        SDL_RenderPresent(Render::object);
    }

    ~Render() {
        SDL_DestroyRenderer(Render::object);
    }
};


class Engine {
public:
    Window *window;
    Render *render;

    Engine() {
        Engine::window = new Window();
        Engine::render = new Render(window);
    }

    void loop() {
        SDL_Event event;
        while (true) {
            if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
                break;
            }
        }
    }

    ~Engine() {
        delete Engine::window;
        delete Engine::render;

        SDL_Quit();
    }
};


int main() {
    Engine *engine = new Engine();

    engine->render->clear();

    engine->render->draw(300, 300, RED);
    engine->render->draw(350, 350, GREEN);
    engine->render->draw(330, 320);
    engine->render->flush();

    engine->loop();

    delete engine;

    return 0;
}
