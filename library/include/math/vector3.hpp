#pragma once

#include <cmath>

namespace my::math
{
    class Vector3
    {
    public:
        double x;
        double y;
        double z;

        void add(double scalar);
        void add(const Vector3 &other);

        void subtract(double scalar);
        void subtract(const Vector3 &other);

        void scale(double scalar);

        double dot(const Vector3 &other) const;
        Vector3 cross(const Vector3 &other) const;

        Vector3 projectedOnto(const Vector3 &other) const;

        double magnitude() const;

        Vector3();
        explicit Vector3(double scalar); // note: I don't want `.dot(double)` to be implicitely converted to `.dot(Vector3)`
        Vector3(double x, double y, double z);

        Vector3 operator+(double scalar) const;
        Vector3 &operator+=(double scalar);
        Vector3 operator-(double scalar) const;
        Vector3 &operator-=(double scalar);
        Vector3 operator*(double scalar) const;
        Vector3 &operator*=(double scalar);

        Vector3 operator+(const Vector3 &other) const;
        Vector3 &operator+=(const Vector3 &other);
        Vector3 operator-(const Vector3 &other) const;
        Vector3 &operator-=(const Vector3 &other);

        bool operator==(const Vector3 &other) const;
    };
}