#include "collider.h"

Collider::Collider(
	Vector2D_f position,
	Vector2D_f size,
	bool status_collision
) {
	this->_position = position;
	this->_size = size;
	this->_status_collision = status_collision;

}

void Collider::swich_Status_Collision() {
	if (this->_status_collision) this->_status_collision = false;
	else this->_status_collision = true;

}

bool Collider::get_Status_Collision() const {
	return this->_status_collision;

}

void Collider::set_Position(Vector2D_f position) {
	this->_position = position;

}

Vector2D_f Collider::get_Position() const {
	return this->_position;

}

void Collider::set_Size(Vector2D_f size) {
	this->_size = size;

}

Vector2D_f Collider::get_Size() const {
	return this->_size;

}