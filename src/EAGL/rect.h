#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vectors.h"
#include "transform.h"


class Rect : public Transform {
private:

    Vector3D_f _position = Vector3D_f(0.0f, 0.0f, 0.0f);

    Vector3D_f _size = Vector3D_f(0.0f, 0.0f, 0.0f);

    int _count_point = 4;

    Vector3D_f _points[4];

    Vector2D_f _texture_points[4];

    Vector3D_f _origin = Vector3D_f(0.0f, 0.0f, 0.0f);

    float _color[3] = { 0.0f, 0.0f, 0.0f};

    void _Update();

public:

    Rect() = default;

    Vector3D_f get_Position() const;
    void set_Position(Vector3D_f position);

    Vector3D_f get_Size() const;
    void set_Size(Vector3D_f size);

    int get_Count_Point() const;

    Vector3D_f get_Point(int index) const;
    Vector3D_f* get_Points();

    void set_Color(Vector3D_f color);
    float* get_Color();

    void set_Texture_Points(Vector2D_f p0, Vector2D_f p1, Vector2D_f p2, Vector2D_f p3);
    Vector2D_f* get_Texture_Points();
};



