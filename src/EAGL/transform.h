#pragma once

#include "vectors.h"
#include "primitive.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>




class Transform {
private:

    Vector3D_f _scale = Vector3D_f(1.0f, 1.0f, 1.0f);

    int _rotate = 0;

public:

    Transform() = default;

    void set_Scale(Vector3D_f scale);

    void change_Rotate(int rotate);
    void TRANSFORM_SCALE(Primitive& primitive);

    void CONVERT_CORDINAT(Primitive primitive, GLfloat* cordinat, Vector3D_f screen_size);

};



