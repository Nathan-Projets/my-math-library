#include "math/vector3.hpp"

namespace my::math
{
    void Vector3::add(const Vector3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    void Vector3::subtract(const Vector3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    Vector3::Vector3(float value) : x(value), y(value), z(value)
    {
    }

    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
    {
    }

    Vector3 Vector3::operator+(const Vector3 &other) const
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 &Vector3::operator+=(const Vector3 &other)
    {
        add(other);
        return *this;
    }

    Vector3 Vector3::operator-(const Vector3 &other) const
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 &Vector3::operator-=(const Vector3 &other)
    {
        subtract(other);
        return *this;
    }
}