#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cmath>
#include <cassert>
#include <iostream>


class Vector {
public:
    float x;
    float y;
    float z;
    float w;

    Vector();

    Vector(float, float, float, float w=0);

    Vector(const Vector &);

    float length();

    Vector& normalize();

    friend std::ostream& operator<<(std::ostream &, const Vector &);

    Vector operator-();

    Vector operator+(const float) const;

    Vector operator+(const Vector&) const;

    Vector& operator+=(const float);

    Vector& operator+=(const Vector&);

    Vector operator-(const float) const;

    Vector operator-(const Vector&) const;

    Vector& operator-=(const float);

    Vector& operator-=(const Vector&);

    Vector operator*(const float) const;

    Vector operator*(const Vector&) const;

    Vector& operator*=(const float);

    Vector& operator*=(const Vector&);

    Vector operator/(const float) const;

    Vector operator/(const Vector&) const;

    Vector& operator/=(const float);

    Vector& operator/=(const Vector&);
};

#endif
