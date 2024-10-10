#include "texture.h"


GLuint& Texture::get_ID() {
    return this->_ID;

}

void Texture::set_Name_Texture(const char* name_texture) {
    this->_name_texture = name_texture;
    
}

std::string Texture::get_Name_Texture() const {
    return _name_texture;
}

void Texture_Manager::add_Texture(
    const char* path_texture,
    const char* name_texture,
    const char* type_image
) {

    this->_texture.resize(this->_texture.size() + 1);

    stbi_set_flip_vertically_on_load(true);

    glGenTextures(1, &this->_texture[this->_texture.size() - 1].get_ID());
    glBindTexture(GL_TEXTURE_2D, this->_texture[this->_texture.size() - 1].get_ID());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannals;

    unsigned char* data = stbi_load(path_texture, &width, &height, &nrChannals, 0);

    if (data) {

        if (type_image = "JPG") {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

        }
        else if (type_image = "PNG") {

            std::cout << "PNG" << std::endl;
            stbi_image_free(data);

        }
        else {

            std::cout << "Uncorrect type!!!" << std::endl;

        }
        
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);


    this->_texture[this->_texture.size() - 1].set_Name_Texture(name_texture);


}

Texture Texture_Manager::get_Texture(const char* name_texture) const {
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
        cout << "Texture " << i << " - " << "Name: " << this->_texture[i].get_Name_Texture() << " ID: " << this->_texture[i].get_ID() << endl;

    }
}
