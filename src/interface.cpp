#include "interface.h"

void Interface_Element::set_Name_Link_Sprite(std::string name_link_sprite) {
    this->_name_link_sprite = name_link_sprite;

}

std::string Interface_Element::get_Name_Link_Sprite() const {
    return this->_name_link_sprite;

}

void Interface_Element::set_Interface_Element(
    std::string name_link_sprite,
    Vector2D_f position,
    Vector2D_f size,
    bool status_collision
) {
    this->set_Name_Link_Sprite(name_link_sprite);

    this->_collider = Collider(
        position,
        size,
        status_collision
    );

}

void Interface_Element::set_Position(Vector2D_f position) {
    this->_collider.set_Position(position);

}

Vector2D_f Interface_Element::get_Position() const {
    return this->_collider.get_Position();

}

void Interface_Element::set_Size(Vector2D_f size) {
    this->_collider.set_Size(size);

}

Vector2D_f Interface_Element::get_Size() const {
    return this->_collider.get_Size();

}

void Interface_Element::set_Status_Collision(bool status_collision) {
    this->_collider.set_Status_Collision(status_collision);

}

bool Interface_Element::get_Status_Collision() const {
    return this->_collider.get_Status_Collision();

}




Interface::Interface(Assets* assets) {

    this->_texture = Texture_Manager();
    this->_sprite = Sprite_Manager(&this->_texture);

    /// LOAD ASSETS ///

    assets->load_asset(
        &this->_texture,
        &this->_sprite,
        "icon_personal.jpg",
        "Icon_Personat_Texture",
        "PNG",
        3,
        std::vector<std::string>{
        "Sprite_Default",
            "Sprite_Hover",
            "Sprite_Active"
    },
        64.0,
        64.0,
        std::vector<Vector2D_f>{
        Vector2D_f(
            0,
            32
        ),
            Vector2D_f(
                32,
                64
            ),
            Vector2D_f(
                0,
                32
            )
    },
        std::vector<Vector2D_f>{
        Vector2D_f(
            0,
            32
        ),
            Vector2D_f(
                0,
                32
            ),
            Vector2D_f(
                32,
                64
            )
    }
    );




    /// SET MAIN MENU INTERFACE

    this->_main_menu_interface.resize(3);
    this->_main_menu_interface[0].set_Interface_Element(
        "Sprite_Default",
        Vector2D_f(
            200.f,
            40.f
        ),
        Vector2D_f(
            200.f,
            50.f
        ),
        true
    );
    this->_main_menu_interface[1].set_Interface_Element(
        "Sprite_Hover",
        Vector2D_f(
            200.f,
            160.f
        ),
        Vector2D_f(
            200.f,
            50.f
        ),
        true
    );
    this->_main_menu_interface[2].set_Interface_Element(
        "Sprite_Active",
        Vector2D_f(
            200.f,
            280.f
        ),
        Vector2D_f(
            200.f,
            50.f
        ),
        true
    );

}


Texture_Manager& Interface::get_Texture() {
    return this->_texture;

}

Sprite_Manager& Interface::get_Sprite() {
    return this->_sprite;

}

std::vector<Interface_Element>& Interface::get_Main_Menu_Interface() {
    return this->_main_menu_interface;

}