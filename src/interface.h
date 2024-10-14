#pragma once

#include "collider.h"
#include "load_assets.h"

class Interface_Element {
private:

	std::string _name_link_sprite;

	Collider _collider;

public:

	Interface_Element() = default;

	void set_Name_Link_Sprite(std::string name_link_sprite);
	std::string get_Name_Link_Sprite() const;

	void set_Interface_Element(
		std::string name_link_sprite,
		Vector2D_f position,
		Vector2D_f size,
		bool status_collision
	);

	void set_Position(Vector2D_f position);
	Vector2D_f get_Position() const;

	void set_Size(Vector2D_f size);
	Vector2D_f get_Size() const;

	void set_Status_Collision(bool status_collision);
	bool get_Status_Collision() const;

};


class Interface {
private:

	Texture_Manager _texture;
	Sprite_Manager _sprite;

	std::vector<Interface_Element> _main_menu_interface;


public:

	Interface() = default;

	Interface(Assets* assets);


	Texture_Manager& get_Texture();
	Sprite_Manager& get_Sprite();

	std::vector<Interface_Element>& get_Main_Menu_Interface();

};