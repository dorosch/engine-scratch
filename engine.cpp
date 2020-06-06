#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include <SDL2/SDL.h>


const SDL_Color BLACK = {.r = 0, .g = 0, .b = 0};
const SDL_Color RED = {.r = 255, .g = 0, .b = 0};
const SDL_Color GREEN = {.r = 0, .g = 255, .b = 0};
const SDL_Color BLUE = {.r = 0, .g = 0, .b = 255};
const SDL_Color WHITE = {.r = 255, .g = 255, .b = 255};


class Vector {
public:
    float x;
    float y;
    float z;
};


class Triangle {
public:
    Vector v0;
    Vector v1;
    Vector v2;

    Triangle(Vector v0, Vector v1, Vector v2) {
        Triangle::v0 = v0;
        Triangle::v1 = v1;
        Triangle::v2 = v2;
    }
};


class Model {
/**
 * A very simple class to load models from a .obj file.
 *
 * The file contains a set of triangle vertices:
 *     v -1.2 2.1 0.0
 *     v -2.0 0.5 1.0
 *     v -0.3 0.1 2.0
 *     ...
 *     f 1/3725 2/2454 3/2447
 *     ...
 *
 * Each line starting with 'v' is a vertex. The vertex is
 * represented in three-dimensional space by three coordinates:
 * x, y, z.
 *
 * Each line that starts with 'f' is a facet. Each facet is
 * represented by a triangle. Each first number in a facet
 * definition is the vertex index.
 *
 * In the example file, vertex 'f' describes a triangle:
 *     (-1.2, 2.1, 0.0)
 *     (-2.0, 0.5, 1.0)
 *     (-0.3, 0.1, 2.0)
 */

private:
    std::string _file_path;
    std::vector<Vector> _vertices;

public:
    std::vector<Triangle> facets;

    Model(std::string file_path) {
        Model::_file_path = file_path;
    }

    void load() {
        std::string line;
        std::ifstream file(Model::_file_path);

        if (file.is_open() == false) {
            std::cerr <<
                "Error render model: " << Model::_file_path << std::endl;
            return;
        }

        while (std::getline(file, line)) {
            char type;
            std::string x, y, z;
            std::stringstream string(line);

            if (line.rfind("v ", 0) == false) {
                Vector v;

                string >> type >> x >> y >> z;

                v.x = std::stof(x);
                v.y = std::stof(y);
                v.z = std::stof(z);

                Model::_vertices.push_back(v);
            }

            if (line.rfind("f ", 0) == false) {
                int index[3];
                char separator = '/';
                std::string a, b;

                string >> type >> x >> y >> z;

                std::stringstream facet_x(x);
                std::getline(facet_x, a, separator);
                std::getline(facet_x, b, separator);
                index[0] = std::stoi(a) - 1;

                std::stringstream facet_y(y);
                std::getline(facet_y, a, separator);
                std::getline(facet_y, b, separator);
                index[1] = std::stoi(a) - 1;

                std::stringstream facet_z(z);
                std::getline(facet_z, a, separator);
                std::getline(facet_z, b, separator);
                index[2] = std::stoi(a) - 1;

                Model::facets.push_back({
                    Model::_vertices[index[0]],
                    Model::_vertices[index[1]],
                    Model::_vertices[index[2]],
                });
            }
        }
    }
};


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
            std::cerr << "Error creating window" << std::endl;
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
            std::cerr << "Error creating render" << std::endl;
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


class AbstractPrimitive {
/**
 * Abstract class graphic primitives
 */

public:
    Render *render;

    AbstractPrimitive(Render *render) {
        AbstractPrimitive::render = render;
    }
};


class Point: public AbstractPrimitive {
public:
    Point(Render *render): AbstractPrimitive(render) {}

    void draw(int x, int y, SDL_Color color=WHITE) {
        Point::render->draw(x, y, color);
    }
};


class Line: public AbstractPrimitive {
public:
    Line(Render *render): AbstractPrimitive(render) {}

    void draw(int x0, int y0, int x1, int y1, SDL_Color color=WHITE) {
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
};


int main() {
    Engine *engine = new Engine();
    Point point(engine->render);
    Line line(engine->render);

    Model deer("models/deer.obj");
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
