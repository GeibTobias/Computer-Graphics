#include <iostream>
#include <core\color.h>
#include <algorithm>

using namespace std;
using namespace rt;

RGBColor operator*(float scalar, const RGBColor& b)
{
	RGBColor col(scalar * b.r, scalar * b.g, scalar * b.b);
	return col;
}

RGBColor operator*(const RGBColor& a, float scalar)
{
	return rt::operator*(scalar, a);
}

RGBColor operator/(const RGBColor& a, float scalar)
{
	RGBColor col(scalar / a.r, scalar / a.g, scalar / a.b);
	return col;
}

RGBColor RGBColor::operator+(const RGBColor& c) const
{
	RGBColor col(r + c.r, g + c.g, b + c.b);
	return col;
}

RGBColor RGBColor::operator-(const RGBColor& c) const
{
	RGBColor col(r - c.r, g - c.g, b - c.b);
	return col;
}

RGBColor RGBColor::operator*(const RGBColor& c) const
{
	RGBColor col(r * c.r, g * c.g, b * c.b);
	return col;
}

bool RGBColor::operator==(const RGBColor& b) const
{
	return (r == b.r) && (g == b.g) && (this->b == b.b);
}

bool RGBColor::operator!=(const RGBColor& b) const
{
	return !this->operator==(b);
}

RGBColor RGBColor::clamp() const
{
	RGBColor col(r / 255, g / 255, b / 255);
	return col;
}
