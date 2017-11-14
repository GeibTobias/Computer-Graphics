#ifndef CG1RAYTRACER_VECTOR_HEADER
#define CG1RAYTRACER_VECTOR_HEADER

#include <core/macros.h>

namespace rt {

class Float4;
class Point;
class ALIGN(16) Vector {
    public:
        float x, y, z;

        Vector() {}
        Vector(float x, float y, float z) : x(x), y(y), z(z) {}
        explicit Vector(const Float4& f4);

        static Vector rep(float v) { return Vector(v,v,v); }

        Vector operator+(const Vector& b) const{return Vector(b.x + this->x, b.y + this->y, b.z + this->z);}
        Vector operator-(const Vector& b) const{return Vector(b.x - this->x, b.y - this->y, b.z - this->z);}

        Vector normalize() const{return Vector(this->x/this->length(),this->x/this->length(),this->x/this->length());}


        Vector operator-() const{return Vector(this.x * -1.0f,this.y * -1.0f, this.z * -1.0f);}

        float lensqr() const{ return lsqr = this->x^2 + this->y^2 + this->z^2;}
        float length() const{ return std::sqrt(lensqr());}

        bool operator==(const Vector& b) const{return (b.x == this->x && b.y == this->y && b.z == this->z);}
        bool operator!=(const Vector& b) const{return !(b==this);}
};

Vector operator*(float scalar, const Vector& b);
Vector operator*(const Vector& a, float scalar);
Vector operator/(const Vector& a, float scalar);
Vector cross(const Vector& a, const Vector& b);
float dot(const Vector& a, const Vector& b);

Vector min(const Vector& a, const Vector& b){}
Vector max(const Vector& a, const Vector& b);

Point operator+(const Point& a, const Vector& b);
Point operator+(const Vector& a, const Point& b);
Point operator-(const Point& a, const Vector& b);
Point operator*(const Float4& scale, const Point& p);

}

#endif
