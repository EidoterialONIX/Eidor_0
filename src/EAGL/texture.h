#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stb_image.h"
#include "vector"
#include "string.h"
#include <iostream>




class Texture {
private:

    GLuint _ID = 0;
    std::string _name_texture;


public:

    Texture() = default;

    GLuint& get_ID();

    void set_Name_Texture(const char* name_texture);
    std::string get_Name_Texture() const;

};



class Texture_Manager {
private:

    std::vector<Texture> _texture;

public:

    Texture_Manager() = default;

    void add_Texture(
        const char* path_texture,
        const char* name_texture,
        const char* type_image
    );

    Texture get_Texture(const char* name_texture) const;
    
    void show_Info();

};
