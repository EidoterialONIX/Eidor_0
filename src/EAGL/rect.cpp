#include "rect.h"

void Rect::set_Position(Vector2D_f position) {
	this->_position = position;

	this->set_Surface(
		this->_position,
		this->_size
	);

}

Vector2D_f Rect::get_Position() const {
	return this->_position;

}

void Rect::set_Size(Vector2D_f size) {
	this->_size = size;

	this->set_Surface(
		this->_position,
		this->_size
	);

}

Vector2D_f Rect::get_Size() const {
	return this->_size;

}

void Rect::set_Scale(GLfloat scale) {
	this->_scale = scale;

}

GLfloat Rect::get_Scale() const {
	return this->_scale;

}

void Rect::set_Rotate(GLuint rotate) {
	this->_rotate = rotate;

}

GLuint Rect::get_Rotate() const {
	return this->_rotate;

}

void Rect::set_Origin(Vector2D_f origin) {
	this->_origin = origin;

}

Vector2D_f Rect::get_Origin() const {
	return this->_origin;

}

void Rect::set_Color(Color color) {
	this->_color = color;

}

Color Rect::get_Color() const {
	return this->_color;

}

void Rect::set_Texture_Points(Vector2D_f* texture_points) {
	this->_texture_points[0] = texture_points[0]; this->_texture_points[1] = texture_points[1];
	this->_texture_points[2] = texture_points[2]; this->_texture_points[3] = texture_points[3];

}

Vector2D_f* Rect::pull_Texture_Points() const {
	Vector2D_f texture_points[4];

	texture_points[0] = this->_texture_points[0]; texture_points[1] = this->_texture_points[1];
	texture_points[2] = this->_texture_points[2]; texture_points[3] = this->_texture_points[3];

	return texture_points;

}

void Rect::out_Information() {
	using namespace std;

	this->out_Information();

	cout
		<< "Position: "
		<< "( X: "
		<< this->_position.x
		<< ", Y: "
		<< this->_position.y
		<< " ) "
		<< "Size: "
		<< "( X: "
		<< this->_size.x
		<< ", Y: "
		<< this->_size.y
		<< " ) "
		<< endl;
	cout
		<< "Scale: "
		<< this->_scale
		<< "Rotate: "
		<< this->_rotate
		<< "Origin: "
		<< "( X: "
		<< this->_origin.x
		<< ", Y: "
		<< this->_origin.y
		<< " ) "
		<< endl;

	this->_color.out_Information();

}