#include "vector.h"

Vector operator + (const Vector &a, const Vector &b)
{
	return Vec3( a.x+b.x, a.y+b.y, a.z+b.z);
}
Vector operator - (const Vector &a, const Vector &b)
{
	return Vec3( a.x-b.x, a.y-b.y, a.z-b.z);
}

float dotProd(const Vector &a, const Vector &b)
{
	return (a.x*b.x) + (a.y*b.y) + (a.z*b.z);
}
Vec3 crossProd(const Vector &a, const Vector &b)
{
	return Vector(
		a.y*b.z - b.y*a.z,
		a.z*b.x - b.z*a.x,
		a.x*b.y - b.x*a.y
		);
}
