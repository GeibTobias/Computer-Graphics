#ifndef CG1RAYTRACER_VECTOR_HEADER
#define CG1RAYTRACER_VECTOR_HEADER

#include <core/macros.h>

namespace rt {

class Float4;
class Point;
class Vector {
    public:
        float x, y, z;

        Vector() {}
        Vector(float x, float y, float z) : x(x), y(y), z(z) {}
        explicit Vector(const Float4& f4);

        static Vector rep(float v) { return Vector(v,v,v); }

        Vector operator+(const Vector& b) const{return Vector(b.x + this->x, b.y + this->y, b.z + this->z);}
        Vector operator-(const Vector& b) const{return Vector(b.x - this->x, b.y - this->y, b.z - this->z);}

        Vector normalize() const{return Vector(this->x/this->length(),this->x/this->length(),this->x/this->length());}


        Vector operator-() const;

        float lensqr() const{ return Vector(this->x^2,this->y^2,this->z^2);}
        float length() const; //find out how to sqrt

        bool operator==(const Vector& b) const;
        bool operator!=(const Vector& b) const;
};

Vector operator*(float scalar, const Vector& b);
Vector operator*(const Vector& a, float scalar);
Vector operator/(const Vector& a, float scalar);
Vector cross(const Vector& a, const Vector& b);
float dot(const Vector& a, const Vector& b);

Vector min(const Vector& a, const Vector& b);
Vector max(const Vector& a, const Vector& b);

Point operator+(const Point& a, const Vector& b);
Point operator+(const Vector& a, const Point& b);
Point operator-(const Point& a, const Vector& b);
Point operator*(const Float4& scale, const Point& p);

}

#endif
