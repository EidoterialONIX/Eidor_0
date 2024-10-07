#include "player.h"


Player::Player(
	const char* path_texture,
	Vector2D_f start_position,
	Vector2D_f start_size,
	Vector2D_f max_size_map
) {

	this->_sprite = Texture(path_texture);

	this->_collider = Collider(max_size_map, start_position, start_size);

	this->_body.set_Position(Vector3D_f(start_position.x, start_position.y, 0.0f));
	this->_body.set_Size(Vector3D_f(start_size.x, start_size.y, 0.0f));

}

Rect& Player::get_Body() {
	return this->_body;

}

Texture& Player::get_Sprite() {
	return this->_sprite;

}