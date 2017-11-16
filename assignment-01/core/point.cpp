#include <iostream>
#include <core\point.h>
#include <core\vector.h>
#include <algorithm>

using namespace std;
using namespace rt;

Vector rt::Point::operator-(const Point &b) const
{
	Vector vec(b.x - x, b.y - y, b.z - z);
	return vec;
}

bool rt::Point::operator==(const Point& b) const 
{
	return (x == b.x) && (y == b.y) && (z == b.z);
}

bool rt::Point::operator!=(const Point& b) const 
{
	return !this->operator==(b);
}

Point operator*(float scalar, const Point& b)
{
	Point point(scalar * b.x, scalar * b.y, scalar * b.z);
	return point;
}

Point operator*(const Point& a, float scalar)
{
	Point point(a.x * scalar, a.y* scalar, a.z * scalar);
	return point;
}

Point min(const Point& a, const Point& b)
{
	Point point(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
	return point;
}

Point max(const Point& a, const Point& b)
{
	Point point(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
	return point;
}