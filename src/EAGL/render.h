#pragma once

#include <glad/glad.h>

#include "vectors.h"
#include "shader.h"
#include "transform.h"
#include "texture.h"
#include "sprite.h"
#include "rect.h"

class Render {

    Vector2D_f _screen_size;

    Transform _transform;

    void CORDINAT_CONVERTER(
        Vector2D_f* positional_points,
        GLuint count_points
    );

public:

    Render(Vector2D_f screen_size);

    void DrawBackground(
        Rect RECT,
        Shader_Program shader,
        GLuint& texture_id,
        Vector2D_f transform
    );

    void DrawSprite(
        Rect RECT,
        Shader_Program shader,
        GLuint& texture_id
    );

};



