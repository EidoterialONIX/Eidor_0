#include "body.h"

Body::Body(
	Vector2D_f position,
	Vector2D_f size
) {
	this->set_Body(
		position,
		size
	);

}

void Body::set_Body(
	Vector2D_f position,
	Vector2D_f size
) {
	this->set_Position(position);
	this->set_Size(size);

}

void Body::set_Position(Vector2D_f position) {
	this->_position = position;

}

Vector2D_f Body::get_Position() const {
	return this->_position;

}

void Body::set_Size(Vector2D_f size) {
	this->_size = size;

}

Vector2D_f Body::get_Size() const {
	return this->_size;

}