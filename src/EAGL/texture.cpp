#include "texture.h"


void Texture::load_Texture(
    const char* path_texture,
    GLuint b_c
) {
    stbi_set_flip_vertically_on_load(true);

    glGenTextures(1, &this->_ID);
    glBindTexture(GL_TEXTURE_2D, this->_ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    int width, height, nrChannals;

    unsigned char* data = stbi_load(path_texture, &width, &height, &nrChannals, 0);


    if (data) {

        if (b_c == 3) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

        }
        else if (b_c == 4) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

        }
        else {
            std::cout << "Uncorrect type!!!" << std::endl;

        }
        
    }
    else {
        std::cout << "Failed to load texture" << std::endl;

    }

    stbi_image_free(data);

}

GLuint& Texture::get_ID() {
    return this->_ID;

}