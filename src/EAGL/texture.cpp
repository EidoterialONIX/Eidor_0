#include "texture.h"


Texture::Texture(std::string name_texture) {
    this->_name_texture = name_texture;

}


GLuint& Texture::get_ID() {
    return this->_ID;

}


std::string Texture::get_Name_Texture() const {
    return _name_texture;

}

void Texture_Manager::add_Texture(
    std::string path_texture,
    std::string name_texture,
    std::string type_image
) {
    this->_texture.resize(this->_texture.size() + 1);
    this->_texture[this->_texture.size() - 1] = Texture(name_texture);

    stbi_set_flip_vertically_on_load(true);

    glGenTextures(1, &this->_texture[this->_texture.size() - 1].get_ID());
    glBindTexture(GL_TEXTURE_2D, this->_texture[this->_texture.size() - 1].get_ID());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    int width, height, nrChannals;

    unsigned char* data = stbi_load(path_texture.c_str(), &width, &height, &nrChannals, 0);

    if (data) {

        if (type_image == "JPG") {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

        }
        else if (type_image == "PNG") {

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

Texture Texture_Manager::get_Texture(std::string name_texture) const {
    for (int i{ 0 }; i < this->_texture.size(); i++) {

        if (this->_texture[i].get_Name_Texture() == name_texture) return this->_texture[i];

    }

    std::cout << "Not find texture: " << name_texture << std::endl;
    return Texture();

}

void Texture_Manager::show_Info() {
    using namespace std;

    cout << " --- ALL TEXTURE ---" << endl;
    cout << endl;
    
    for (int i{ 0 }; i < this->_texture.size(); i++) {
        cout
            << "Texture "
            << i
            << " - "
            << "Name: "
            << this->_texture[i].get_Name_Texture()
            << " ID: "
            << this->_texture[i].get_ID()
            << endl;

    }

}
