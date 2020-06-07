#ifndef __MATH_HPP__
#define __MATH_HPP__

#include "math/vector.hpp"


class Triangle {
public:
    Vector v0;
    Vector v1;
    Vector v2;

    Triangle(Vector, Vector, Vector);
};

#endif
