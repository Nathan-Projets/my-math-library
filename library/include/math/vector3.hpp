#pragma once

namespace my::math
{
    class Vector3
    {
    public:
        float x;
        float y;
        float z;

        void add(const Vector3 &other);
        void subtract(const Vector3 &other);

        Vector3(float value);
        Vector3(float x, float y, float z);

        Vector3 operator+(const Vector3 &other) const;
        Vector3 &operator+=(const Vector3 &other);
        Vector3 operator-(const Vector3 &other) const;
        Vector3 &operator-=(const Vector3 &other);
    };
}