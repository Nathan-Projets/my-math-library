#pragma once

#include <cmath>

namespace my::math
{
    class Vector3
    {
    public:
        float x;
        float y;
        float z;

        void add(float scalar);
        void add(const Vector3 &other);

        void subtract(float scalar);
        void subtract(const Vector3 &other);

        void scale(float scalar);

        float dot(const Vector3 &other) const;
        Vector3 cross(const Vector3 &other) const;

        float length() const;

        Vector3();
        explicit Vector3(float scalar);  // note: I don't want `.dot(float)` to be implicitely converted to `.dot(Vector3)`
        Vector3(float x, float y, float z);

        Vector3 operator+(float scalar) const;
        Vector3 &operator+=(float scalar);
        Vector3 operator-(float scalar) const;
        Vector3 &operator-=(float scalar);
        Vector3 operator*(float scalar) const;
        Vector3 &operator*=(float scalar);

        Vector3 operator+(const Vector3 &other) const;
        Vector3 &operator+=(const Vector3 &other);
        Vector3 operator-(const Vector3 &other) const;
        Vector3 &operator-=(const Vector3 &other);

        bool operator==(const Vector3& other) const;
    };
}