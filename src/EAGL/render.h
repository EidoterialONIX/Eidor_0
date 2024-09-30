#pragma once

#include "vectors.h"
#include "primitive.h"
#include "shader.h"
#include "texture.h"
#include "rect.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>



class Render {

    Vector3D_f _screen_size = Vector3D_f(0.0f, 0.0f, 0.0f);

    GLuint VBO = 0;
    GLuint VAO = 0;

    Primitive _primitive;

    GLfloat _cordinat[24];


public:

    Render(Vector3D_f screen_size);

    void Draw(Rect RECT, Shader_Program shader_program, Texture& texture);

};



