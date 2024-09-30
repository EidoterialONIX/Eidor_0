#pragma once
#include "vectors.h"



class Primitive {
private:

    Vector3D_f _point[3];

public:

    Primitive() = default;

    Primitive(Vector3D_f v0, Vector3D_f v1, Vector3D_f v2);

    Vector3D_f& get_Point(int index);
    void set_Point(int index, Vector3D_f v);

    void operator=(Primitive p);

    bool operator==(Primitive p);

    void operator+=(Primitive p);
    void operator-=(Primitive p);
    void operator*=(Primitive p);
    void operator/=(Primitive p);

    Primitive operator+(Primitive p);
    Primitive operator-(Primitive p);
    Primitive operator*(Primitive p);
    Primitive operator/(Primitive p);

};


