#pragma once


#include "EAGL/sprite.h"
#include "collider.h"


class Location_Object {
private:

	std::string _name_link_sprite;

	Collider _collider;

public:

	Location_Object() = default;

	void set_Name_Link_Sprite(const char* name_link_sprite);
	std::string get_Name_Link_Sprite() const;

	void set_Location_Object(
		const char* name_link_sprite,
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

	void show_Info();

};
