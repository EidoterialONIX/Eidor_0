#include "location_object.h"


std::string Location_Object::get_Name_Link_Sprite() const {
	return this->_name_link_sprite;

}

void Location_Object::set_Position_Collider(Vector2D_f position) {
	this->_collider.set_Position(position);

}

void Location_Object::set_Size_Collider(Vector2D_f size) {
	this->_collider.set_Size(size);

}

void Location_Object::swich_Status_Collision() {
	this->_collider.swich_Status_Collision();

}

void Location_Object::set_Location_Object(
	const char* name_link_sprite,
	Vector2D_f position,
	Vector2D_f size,
	bool status_collision
) {
	this->_name_link_sprite = name_link_sprite;
	
	this->_collider = Collider(
		position,
		size,
		status_collision
	);

}

Collider Location_Object::get_Collider() const {
	return this->_collider;

}

Location_Object_Manager::Location_Object_Manager(Sprite_Manager* sprite_manager) {
	this->_sprite_manager = sprite_manager;

}

void Location_Object_Manager::add_Location_Object(
	const char* name_link_sprite,
	Vector2D_f position,
	Vector2D_f size,
	bool status_collision
) {
	this->_location_object.resize(this->_location_object.size() + 1);
	this->_location_object[this->_location_object.size() - 1].set_Location_Object(
		name_link_sprite,
		position,
		size,
		status_collision
	);

}

std::vector<Rect> Location_Object_Manager::pull_Location_Object() {

	std::vector<Rect> location_object;

	location_object.resize(this->_location_object.size());

	for (int i{ 0 }; i < location_object.size(); i++) {
		location_object[i] = this->_sprite_manager->get_Sprite(this->_location_object[i].get_Name_Link_Sprite()).get_Surface();

	}

	return location_object;
}

std::vector<Location_Object>& Location_Object_Manager::get_Location_Object() {
	return this->_location_object;

}

void Location_Object_Manager::show_Info() {
	using namespace std;

	cout << " --- ALL Location Object ---" << endl;
	cout << endl;

	for (int i{ 0 }; i < this->_location_object.size(); i++) {
		cout << "Location object " << i << " - " << "Name link sprite: " << this->_location_object[i].get_Name_Link_Sprite() << endl;

	}


}