#include <math.h>

class Vector3D
{
public:
    float x;
    float y;
    float z;
    Vector3D(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void set(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    ~Vector3D()
    {
        delete this;
    }
    Vector3D copy()
    {
        return Vector3D(this->x, this->y, this->z);
    }
    float mag()
    {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }
    float magSq()
    {
        return this->mag() * this->mag();
    }
    void add(Vector3D v)
    {
        this->x += v.x;
        this->y += v.y;
        this->z += v.z;
    }
    static Vector3D add(Vector3D v1, Vector3D v2)
    {
        return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }
    void sub(Vector3D v)
    {
        this->x = v.x - this->x;
        this->y = v.y - this->x;
        this->z = v.z - this->x;
    }
    static Vector3D sub(Vector3D v1, Vector3D v2)
    {
        return Vector3D(v2.x - v1.x, v2.y - v1.y, v2.z - v1.z);
    }
    void mul(float s)
    {
        this->x *= s;
        this->y *= s;
        this->z *= s;
    }
    static Vector3D mul(Vector3D v, float s)
    {
        return Vector3D(v.x * s, v.y * s, v.z * s);
    }
    void div(float s)
    {
        this->x /= s;
        this->y /= s;
        this->z /= s;
    }
    static Vector3D div(Vector3D v, float s)
    {
        return Vector3D(v.x / s, v.y / s, v.z / s);
    }
    float dist(Vector3D v)
    {
        return (sub(*this, v)).mag();
    }
    float dot(Vector3D v)
    {
        return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
    }
    Vector3D cross(Vector3D v)
    {
        return Vector3D((this->y * v.z) - (this->x * v.y), (this->z * v.x) - (this->x * v.z), (this->x * v.y) - (this->y * v.x));
    }
    Vector3D normalize()
    {
        return Vector3D(this->x/this->mag(), this->y/this->mag(), this->z/this->mag());
    }
    void setMag(float s)
    {
        Vector3D tmp = this->normalize();
        this->x = tmp.x * s;
        this->y = tmp.y * s;
        this->z = tmp.z * s;
        tmp.~Vector3D();
    }
    float* array()
    {
        float res[3] = {this->x, this->y, this->z};
        return res;
    }
};