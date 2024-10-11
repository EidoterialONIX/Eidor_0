#include "location_object.h"



void Location_Object::set_Name_Link_Sprite(const char* name_link_sprite) {
	this->_name_link_sprite = name_link_sprite;

}

std::string Location_Object::get_Name_Link_Sprite() const {
	return this->_name_link_sprite;

}


void Location_Object::set_Location_Object(
	const char* name_link_sprite,
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

void Location_Object::set_Position(Vector2D_f position) {
	this->_collider.set_Position(position);

}

Vector2D_f Location_Object::get_Position() const {
	return this->_collider.get_Position();

}

void Location_Object::set_Size(Vector2D_f size) {
	this->_collider.set_Size(size);

}

Vector2D_f Location_Object::get_Size() const {
	return this->_collider.get_Size();

}

void Location_Object::set_Status_Collision(bool status_collision) {
	this->_collider.set_Status_Collision(status_collision);

}

bool Location_Object::get_Status_Collision() const {
	return this->_collider.get_Status_Collision();

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


void Location_Object_Manager::show_Info() {
	using namespace std;

	cout << " --- ALL Location Object ---" << endl;
	cout << endl;

	for (int i{ 0 }; i < this->_location_object.size(); i++) {
		cout
			<< "Location object "
			<< i
			<< " - "
			<< "Name link sprite: "
			<< this->_location_object[i].get_Name_Link_Sprite()
			<< endl;

	}


}