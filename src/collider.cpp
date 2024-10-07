#include "collider.h"

Collider::Collider(Vector2D_f max_size_map, Vector2D_f position, Vector2D_f size) {

	this->_max_size_map = max_size_map;

	this->_position = position;
	this->_size_collider = size;

	this->_Update();

}

void Collider::_Update() {

	this->_size = Vector2D_f(
		this->_correct_scale * this->_size_collider.x,
		this->_correct_scale * this->_size_collider.y
	);

	if (this->_position.x + this->_size.x >= this->_max_size_map.x)
		this->_position.x -= this->_position.x + this->_size.x - this->_max_size_map.x;
	if (this->_position.y + this->_size.y >= this->_max_size_map.y)
		this->_position.y -= this->_position.y + this->_size.y - this->_max_size_map.y;

}

void Collider::reset_zoom() {
	this->_correct_scale = 1.0f;

	this->_Update();

}

void Collider::up_zoom() {
	this->_correct_scale += 0.1;

	if (this->_correct_scale >= this->_max_scale) this->_correct_scale = this->_max_scale;

	this->_Update();

}

void Collider::down_zoom() {
	this->_correct_scale -= 0.1;

	if (this->_correct_scale <= this->_min_scale) this->_correct_scale = this->_min_scale;

	this->_Update();

}