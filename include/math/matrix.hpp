#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>


class Matrix {
public:
    float m[4][4];

    Matrix();

    Matrix(const Matrix&);

    Matrix& operator=(const Matrix&);

    friend std::ostream& operator<<(std::ostream &, const Matrix &);

    float& operator()(const unsigned short int, const unsigned short int);

    float operator()(const unsigned short int, const unsigned short int) const;
};

#endif
