#include "sprite.h"

Sprite::Sprite(
	Color color_filter,
	Vector2D_f texture_point_0, Vector2D_f texture_point_1,
	Vector2D_f texture_point_2, Vector2D_f texture_point_3
) {
	this->set_Sprite(
		color_filter,
		texture_point_0, texture_point_1,
		texture_point_2, texture_point_3
	);

}

void Sprite::set_Sprite(
	Color color_filter,
	Vector2D_f texture_point_0, Vector2D_f texture_point_1,
	Vector2D_f texture_point_2, Vector2D_f texture_point_3
) {
	this->set_Color_Filter(color_filter);
	this->set_Texture_Points(
		texture_point_0, texture_point_1,
		texture_point_2, texture_point_3
	);

}

void Sprite::_UPDATE_FRAME() {
	this->_current_frame++;

	if (this->_current_frame == this->_count_frame) this->_current_frame = 0;

}

void Sprite::bind_Texture(Texture* texture) {
	this->_texture = texture;

}

void Sprite::init_Animation_Unit(
	GLuint count_frame,
	GLuint _space_pixel_x, GLuint _space_pixel_y
) {
	this->_count_frame = count_frame;

	this->_space_pixel_x = _space_pixel_x; this->_space_pixel_y = _space_pixel_y;

}

void Sprite::set_Color_Filter(Color color_filter) {
	this->_color_filter = color_filter;

}

Color Sprite::get_Color_Filter() const {
	return this->_color_filter;

}

void Sprite::set_Texture_Points(
	Vector2D_f texture_point_0,
	Vector2D_f texture_point_1,
	Vector2D_f texture_point_2,
	Vector2D_f texture_point_3
) {
	this->_texture_point_0 = texture_point_0; this->_texture_point_1 = texture_point_1;
	this->_texture_point_2 = texture_point_2; this->_texture_point_3 = texture_point_3;

}

Vector2D_f* Sprite::pull_Texture_Points() const {
	Vector2D_f texture_points[4];

	texture_points[0] = this->_texture_point_0;
	texture_points[1] = this->_texture_point_1;
	texture_points[2] = this->_texture_point_2;
	texture_points[3] = this->_texture_point_3;

	return texture_points;

}

GLuint Sprite::get_Current_Frame() {
	GLuint frame = this->_current_frame;

	this->_UPDATE_FRAME();

	return frame;
	
}

GLuint& Sprite::get_Texture() {
	return this->_texture->get_ID();

}