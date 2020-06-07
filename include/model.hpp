#ifndef __MODEL_HPP__
#define __MODEL_HPP__

#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

#include "math.hpp"
#include "math/vector.hpp"


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

    Model(std::string);

    void load();
};

#endif
