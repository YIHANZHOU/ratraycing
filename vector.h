#include <cmath>

#ifndef VECTOR_INCLUDED
#define VECTOR_INCLUDED

struct Vector
{
    float x, y, z;
    Vector (float x=0, float y=0, float z=0) :x(x), y(y), z(z) {}
    Vector() : x(0.0), y(0.0), z(0.0) {}

    const float Magnitude() const
        return sqrt( x*x + y*y + z*z);
    }
    const Vector UnitVector() const
    {
        const float magnitude = Magnitude();
        return Vector(x/magnitude, y/magnitude, z/magnitude);
    }
    Vector& operator += (const Vector &a) // don't want to change a's values
    {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }
    Vector& operator *= (const Vector &a) // don't want to change a's values
    {
        x *= a.x;
        y *= a.y;
        z *= a.z;
        return *this;
    }
};

Vector operator + (const Vector &a, const Vector &b);
Vector operator - (const Vector &a, const Vector &b);

float dotProd(const Vec3 &a, const Vec3 &b);
Vec3 crossProd(const Vec3 &a, const Vec3 &b);

#endif
