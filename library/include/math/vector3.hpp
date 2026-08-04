#pragma once

#include <cmath>
#include <algorithm>
#include <numbers>

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
        void divide(double scalar);

        double dot(const Vector3 &other) const;
        Vector3 cross(const Vector3 &other) const;

        double angleDegrees(const Vector3 &other) const;
        double angleRadians(const Vector3 &other) const;
        double distance(const Vector3 &other) const;
        Vector3 projectedOnto(const Vector3 &other) const;

        double magnitude() const;

        void normalize();
        Vector3 normalized() const;
        bool isNormalized() const;

        bool almostEquals(const Vector3 &other, double tolerance = 1e-12) const;

        static Vector3 Zero();

        Vector3();
        explicit Vector3(double scalar); // note: I don't want `.dot(double)` to be implicitely converted to `.dot(Vector3)`
        Vector3(double x, double y, double z);
        Vector3(const Vector3 &vector);

        Vector3 operator+(double scalar) const;
        Vector3 &operator+=(double scalar);
        Vector3 operator-(double scalar) const;
        Vector3 &operator-=(double scalar);
        Vector3 operator*(double scalar) const;
        Vector3 &operator*=(double scalar);
        Vector3 operator/(double scalar) const;
        Vector3 &operator/=(double scalar);

        Vector3 operator+(const Vector3 &other) const;
        Vector3 &operator+=(const Vector3 &other);
        Vector3 operator-(const Vector3 &other) const;
        Vector3 &operator-=(const Vector3 &other);

        bool operator==(const Vector3 &other) const;
    };
}