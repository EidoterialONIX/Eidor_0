#pragma once

#include "vectors.h"

#include <iostream>

class Primitive {
private:

    Vector3D_f _point_0{ 0.0f, 0.0f, 0.0f };
    Vector3D_f _point_1{ 0.0f, 0.0f, 0.0f };
    Vector3D_f _point_2{ 0.0f, 0.0f, 0.0f };

public:

    Primitive() = default;

    Primitive(
        Vector3D_f point_0,
        Vector3D_f point_1,
        Vector3D_f point_2
    );

    void set_Primitive(
        Vector3D_f point_0,
        Vector3D_f point_1,
        Vector3D_f point_2
    );

    Vector3D_f* pull_Primitive() const;
    
    void out_Information() const;

    /// OPERATORS ///////////////////
    // //////////////////////////////
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
    // //////////////////////////////
    /// /////////////////////////////

};


