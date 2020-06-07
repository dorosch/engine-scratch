#include "math/vector.hpp"


Vector::Vector() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}


Vector::Vector(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}


Vector::Vector(const Vector &other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
}


float Vector::length() {
    return sqrt(
        this->x * this->x + this->y * this->y + this->z * this->z
    );
}


Vector& Vector::normalize() {
    float length = this->length();

    assert(length != 0);

    (*this) /= length;

    return *this;
}


std::ostream& operator<<(std::ostream &out, const Vector &other) {
    out << "("
        << other.x << ", "
        << other.y << ", "
        << other.z << ", "
        << other.w <<  ")";

    return out;
}


Vector Vector::operator-() {
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
    this->w = -this->w;

    return *this;
}


Vector Vector::operator+(const float scalar) const {
    return Vector(
        this->x + scalar,
        this->y + scalar,
        this->z + scalar,
        this->w + scalar
    );
}


Vector Vector::operator+(const Vector& other) const {
    return Vector(
        this->x + other.x,
        this->y + other.y,
        this->z + other.z,
        this->w + other.w
    );
}


Vector& Vector::operator+=(const float scalar){
    this->x = this->x + scalar;
    this->y = this->y + scalar;
    this->z = this->z + scalar;
    this->w = this->w + scalar;

    return *this;
}


Vector& Vector::operator+=(const Vector& other) {
    this->x = this->x + other.x;
    this->y = this->y + other.y;
    this->z = this->z + other.z;
    this->w = this->w + other.w;

    return *this;
}


Vector Vector::operator-(const float scalar) const {
    return Vector(
        this->x - scalar,
        this->y - scalar,
        this->z - scalar,
        this->w - scalar
    );
}


Vector Vector::operator-(const Vector& other) const {
    return Vector(
        this->x - other.x,
        this->y - other.y,
        this->z - other.z,
        this->w - other.w
    );
}


Vector& Vector::operator-=(const float scalar) {
    this->x = this->x - scalar;
    this->y = this->y - scalar;
    this->z = this->z - scalar;
    this->w = this->w - scalar;

    return *this;
}


Vector& Vector::operator-=(const Vector& other) {
    this->x = this->x - other.x;
    this->y = this->y - other.y;
    this->z = this->z - other.z;
    this->w = this->w - other.w;

    return *this;
}


Vector Vector::operator*(const float scalar) const {
    return Vector(
        this->x * scalar,
        this->y * scalar,
        this->z * scalar,
        this->w * scalar
    );
}


Vector Vector::operator*(const Vector& other) const {
    return Vector(
        this->x * other.x,
        this->y * other.y,
        this->z * other.z,
        this->w * other.w
    );
}


Vector& Vector::operator*=(const float scalar) {
    this->x = this->x * scalar;
    this->y = this->y * scalar;
    this->z = this->z * scalar;
    this->w = this->w * scalar;

    return *this;
}


Vector& Vector::operator*=(const Vector& other) {
    this->x = this->x * other.x;
    this->y = this->y * other.y;
    this->z = this->z * other.z;
    this->w = this->w * other.w;

    return *this;
}


Vector Vector::operator/(const float scalar) const {
    assert(scalar != 0);

    return Vector(
        this->x / scalar,
        this->y / scalar,
        this->z / scalar,
        this->w / scalar
    );
}


Vector Vector::operator/(const Vector& other) const {
    assert(other.x != 0);
    assert(other.y != 0);
    assert(other.z != 0);
    assert(other.w != 0);

    return Vector(
        this->x / other.x,
        this->y / other.y,
        this->z / other.z,
        this->w / other.w
    );
}


Vector& Vector::operator/=(const float scalar) {
    assert(scalar != 0);

    this->x = this->x / scalar;
    this->y = this->y / scalar;
    this->z = this->z / scalar;
    this->w = this->w / scalar;

    return *this;
}


Vector& Vector::operator/=(const Vector& other) {
    assert(other.x != 0);
    assert(other.y != 0);
    assert(other.z != 0);
    assert(other.w != 0);

    this->x = this->x / other.x;
    this->y = this->y / other.y;
    this->z = this->z / other.z;
    this->w = this->w / other.w;

    return *this;
}
