#include "math/vector3.hpp"

namespace my::math
{
    void Vector3::add(float scalar)
    {
        x += scalar;
        y += scalar;
        z += scalar;
    }

    void Vector3::add(const Vector3 &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    void Vector3::subtract(float scalar)
    {
        x -= scalar;
        y -= scalar;
        z -= scalar;
    }

    void Vector3::subtract(const Vector3 &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    void Vector3::scale(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }

    float Vector3::dot(const Vector3 &other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3 Vector3::cross(const Vector3 &other) const
    {
        Vector3 result;
        result.x = y * other.z - z * other.y;
        result.y = z * other.x - x * other.z;
        result.z = x * other.y - y * other.x;
        return result;
    }

    float Vector3::length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    /**
     * ========================================
     * ========================================
     *                 the rest
     */

    Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
    {
    }

    Vector3::Vector3(float scalar) : x(scalar), y(scalar), z(scalar)
    {
    }

    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
    {
    }

    Vector3 Vector3::operator+(float scalar) const
    {
        return Vector3(x + scalar, y + scalar, z + scalar);
    }

    Vector3 &Vector3::operator+=(float scalar)
    {
        add(scalar);
        return *this;
    }

    Vector3 Vector3::operator-(float scalar) const
    {
        return Vector3(x - scalar, y - scalar, z - scalar);
    }

    Vector3 &Vector3::operator-=(float scalar)
    {
        subtract(scalar);
        return *this;
    }

    Vector3 Vector3::operator*(float scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 &Vector3::operator*=(float scalar)
    {
        scale(scalar);
        return *this;
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

    bool Vector3::operator==(const Vector3 &other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }
}