#pragma once
#include <glad/glad.h>

#include "vectors.h"
#include "rect.h"

class Transform {
public:

    Transform() = default;

    void TRANSFORM_SCALE(
        Vector2D_f* positional_points,
        GLfloat scale
    );

    void TRANSFORM_ROTATE(
        Vector2D_f* positional_points,
        GLuint rotate,
        Vector2D_f origin
    );
    
};
