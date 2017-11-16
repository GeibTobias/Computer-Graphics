#include <iostream>
#include <core\macros.h>
#include <core\vector.h>
#include <cmath>
#include <algorithm>
#include <core\point.h>

using namespace std;
using namespace rt;


Vector Vector::operator+(const Vector& b) const {
	Vector vec(x + b.x, y + b.y, z + b.z);
	return vec;
}

Vector operator*(float scalar, const Vector& b) {
	rt::Vector vec1(b.x * scalar, b.y * scalar, b.z * scalar);
	return vec1;
}

Vector operator*(const Vector& a, float scalar)
{
	rt::Vector vec1(a.x * scalar, a.y * scalar, a.z * scalar);
	return vec1;
}

Vector operator/(const Vector& a, float scalar)
{
	rt::Vector vec1(a.x / scalar, a.y / scalar, a.z / scalar);
	return vec1;
}

Vector cross(const Vector& a, const Vector& b)
{
	rt::Vector vec1(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	return vec1;
}

float dot(const Vector& a, const Vector& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vector min(const Vector& a, const Vector& b)
{
	rt::Vector vec1(min(a.x, b.x), min(a.y, b.y), min(a.z,b.z));
	return vec1;
}

Vector max(const Vector& a, const Vector& b)
{
	rt::Vector vec1(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
	return vec1;
}

Point operator+(const Point& a, const Vector& b)
{
	Point p(a.x + b.x, a.y + b.y, a.z + b.z);
	return p;
}

Point operator+(const Vector& a, const Point& b)
{
	return rt::operator+(b, a);
}

Point operator-(const Point& a, const Vector& b)
{
	Point p(a.x - b.x, a.y - b.y, a.z - b.z);
	return p;
}

Point operator*(const Float4& scale, const Point& p)
{
	return Point();
}

Vector Vector::operator-(const Vector &b) const
{
	Vector vec(x - b.x, y - b.y, z - b.z);
	return vec;
}

Vector Vector::normalize() const
{
	Vector vec1 = operator*(this->length(), *this);
	return vec1;
}

Vector Vector::operator-() const
{
	Vector vec(-x, -y, -z);
	return vec;
}

float Vector::lensqr() const
{
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

float Vector::length() const
{
	return sqrt(this->lensqr());
}

bool Vector::operator==(const Vector &b) const
{
	return (x == b.x) && (y == b.y) && (z == b.z);
}

bool Vector::operator!=(const Vector &b) const
{
	return !this->operator==(b);
}
