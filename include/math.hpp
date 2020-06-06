#ifndef __MATH_HPP__
#define __MATH_HPP__


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

    Triangle(Vector, Vector, Vector);
};

#endif
