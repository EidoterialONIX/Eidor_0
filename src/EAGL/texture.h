#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stb_image.h"
#include <iostream>




class Texture {
private:

    GLuint texture = 0;

public:

    Texture() = default;

    Texture(const char* texture_path);

    GLuint get_Texture();

};