#pragma once


#include "EAGL/sprite.h"
#include "collider.h"


class Location_Object {
private:

	std::string _name_link_sprite;

	Collider _collider;

public:

	Location_Object() = default;

	std::string get_Name_Link_Sprite() const;

	void set_Location_Object(
		const char* name_link_sprite,
		Vector2D_f position,
		Vector2D_f size,
		bool status_collision
	);

	void set_Position_Collider(Vector2D_f position);
	void set_Size_Collider(Vector2D_f size);
	void swich_Status_Collision();

	Collider get_Collider() const;

};



class Location_Object_Manager {
private:

	Sprite_Manager* _sprite_manager = nullptr;

	std::vector<Location_Object> _location_object;


public:

	Location_Object_Manager() = default;

	Location_Object_Manager(Sprite_Manager* sprite_manager);

	void add_Location_Object(
		const char* name_link_sprite,
		Vector2D_f position,
		Vector2D_f size,
		bool status_collision
	);

	std::vector<Location_Object>& get_Location_Object();
	std::vector<Rect> pull_Location_Object();

	void show_Info();

};
