#pragma once

#include "glad/glad.h"

#include "stb_image.h"
#include <iostream>

class Texture {
private:

    GLuint _ID = NULL;

public:

    Texture() = default;

    void load_Texture(
        const char* path_texture,
        GLuint b_c
    );

    GLuint& get_ID();

};
