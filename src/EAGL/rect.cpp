#include "rect.h"



void Rect::_Update() {
	this->_points[0] = this->_position;
	this->_points[1] = this->_position + Vector3D_f(this->_size.x, 0.0f, 0.0f);
	this->_points[2] = this->_position + this->_size;
	this->_points[3] = this->_position + Vector3D_f(0.0f, this->_size.y, 0.0f);

}

Vector3D_f Rect::get_Position() const {
	return this->_position;

}

void Rect::set_Position(Vector3D_f position) {
	this->_position = position;
	this->_Update();

}

Vector3D_f Rect::get_Size() const {
	return this->_size;

}

void Rect::set_Size(Vector3D_f size) {
	this->_size = size;
	this->_Update();

}

int Rect::get_Count_Point() const {
	return this->_count_point;

}

Vector3D_f Rect::get_Point(int index) const {
	return this->_points[index];

}

Vector3D_f* Rect::get_Points() {
	return this->_points;

}

void Rect::set_Color(Vector3D_f color) {
	this->_color[0] = color.x; this->_color[1] = color.y; this->_color[2] = color.z;

}

float* Rect::get_Color() {
	return this->_color;

}

void Rect::set_Texture_Points(Vector2D_f p0, Vector2D_f p1, Vector2D_f p2, Vector2D_f p3) {
	this->_texture_points[0] = p0; this->_texture_points[1] = p1;
	this->_texture_points[2] = p2; this->_texture_points[3] = p3;

}

Vector2D_f* Rect::get_Texture_Points() {
	return this->_texture_points;

}



