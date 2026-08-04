#include "math/vector3.hpp"

namespace my::math
{
    void Vector3::add(double scalar)
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

    void Vector3::subtract(double scalar)
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

    void Vector3::scale(double scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }

    double Vector3::dot(const Vector3 &other) const
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

    Vector3 Vector3::projectedOnto(const Vector3 &other) const
    {
        double scaling = this->dot(other);
        double otherMagnitude = other.magnitude();
        double otherMagnitudeSquared = otherMagnitude * otherMagnitude;

        if (otherMagnitudeSquared == 0.0)
        {
            return Vector3{};
        }

        return other * (scaling / otherMagnitudeSquared);
    }

    double Vector3::magnitude() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    void Vector3::normalize()
    {
        double norm = magnitude();
        if (norm == 0.0)
        {
            return; // will need some error handling to warn about these case instead of returning "empty" vector
        }
        x /= norm;
        y /= norm;
        z /= norm;
    }

    Vector3 Vector3::normalized() const
    {
        double norm = magnitude();
        if (norm == 0.0)
        {
            return Vector3{}; // will need some error handling to warn about these case instead of returning "empty" vector
        }
        return {x / norm, y / norm, z / norm};
    }

    /**
     * ========================================
     * ========================================
     *                 the rest
     */

    Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
    {
    }

    Vector3::Vector3(double scalar) : x(scalar), y(scalar), z(scalar)
    {
    }

    Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z)
    {
    }

    Vector3 Vector3::operator+(double scalar) const
    {
        return Vector3(x + scalar, y + scalar, z + scalar);
    }

    Vector3 &Vector3::operator+=(double scalar)
    {
        add(scalar);
        return *this;
    }

    Vector3 Vector3::operator-(double scalar) const
    {
        return Vector3(x - scalar, y - scalar, z - scalar);
    }

    Vector3 &Vector3::operator-=(double scalar)
    {
        subtract(scalar);
        return *this;
    }

    Vector3 Vector3::operator*(double scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 &Vector3::operator*=(double scalar)
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