#include "math/matrix.hpp"


Matrix::Matrix() {
    this->m[0][0] = 1;
    this->m[0][1] = 0;
    this->m[0][2] = 0;
    this->m[0][3] = 0;

    this->m[1][0] = 0;
    this->m[1][1] = 1;
    this->m[1][2] = 0;
    this->m[1][3] = 0;

    this->m[2][0] = 0;
    this->m[2][1] = 0;
    this->m[2][2] = 1;
    this->m[2][3] = 0;

    this->m[3][0] = 0;
    this->m[3][1] = 0;
    this->m[3][2] = 0;
    this->m[3][3] = 1;
}


Matrix::Matrix(const Matrix &other) {
    this->m[0][0] = other.m[0][0];
    this->m[0][1] = other.m[0][1];
    this->m[0][2] = other.m[0][2];
    this->m[0][3] = other.m[0][3];

    this->m[1][0] = other.m[1][0];
    this->m[1][1] = other.m[1][1];
    this->m[1][2] = other.m[1][2];
    this->m[1][3] = other.m[1][3];

    this->m[2][0] = other.m[2][0];
    this->m[2][1] = other.m[2][1];
    this->m[2][2] = other.m[2][2];
    this->m[2][3] = other.m[2][3];

    this->m[3][0] = other.m[3][0];
    this->m[3][1] = other.m[3][1];
    this->m[3][2] = other.m[3][2];
    this->m[3][3] = other.m[3][3];
}


Matrix& Matrix::operator=(const Matrix &other) {
    this->m[0][0] = other.m[0][0];
    this->m[0][1] = other.m[0][1];
    this->m[0][2] = other.m[0][2];
    this->m[0][3] = other.m[0][3];

    this->m[1][0] = other.m[1][0];
    this->m[1][1] = other.m[1][1];
    this->m[1][2] = other.m[1][2];
    this->m[1][3] = other.m[1][3];

    this->m[2][0] = other.m[2][0];
    this->m[2][1] = other.m[2][1];
    this->m[2][2] = other.m[2][2];
    this->m[2][3] = other.m[2][3];

    this->m[3][0] = other.m[3][0];
    this->m[3][1] = other.m[3][1];
    this->m[3][2] = other.m[3][2];
    this->m[3][3] = other.m[3][3];

    return *this;
}


std::ostream& operator<<(std::ostream &out, const Matrix &other) {
    out <<
        "["
            << other.m[0][0] << ", "
            << other.m[0][1] << ", "
            << other.m[0][2] << ", "
            << other.m[0][3] <<
        "]" << std::endl <<
        "["
            << other.m[1][0] << ", "
            << other.m[1][1] << ", "
            << other.m[1][2] << ", "
            << other.m[1][3] <<
        "]" << std::endl <<
        "["
            << other.m[2][0] << ", "
            << other.m[2][1] << ", "
            << other.m[2][2] << ", "
            << other.m[2][3] <<
        "]" << std::endl <<
        "["
            << other.m[3][0] << ", "
            << other.m[3][1] << ", "
            << other.m[3][2] << ", "
            << other.m[3][3] <<
        "]";

    return out;
}


float& Matrix::operator()(
        const unsigned short int row, const unsigned short int column
    ) {
    return this->m[row][column];
}


float Matrix::operator()(
        const unsigned short int row, const unsigned short int column
    ) const {
    return this->m[row][column];
}
