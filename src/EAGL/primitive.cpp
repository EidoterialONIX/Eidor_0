#include "primitive.h"



Primitive::Primitive(Vector3D_f v0, Vector3D_f v1, Vector3D_f v2) {
	this->_point[0] = v0; this->_point[1] = v1; this->_point[2] = v2;

}

Vector3D_f& Primitive::get_Point(int index) {
	return this->_point[index];

}

void Primitive::set_Point(int index, Vector3D_f v) {
	this->_point[index] = v;

}

void Primitive::operator=(Primitive p) {
	this->_point[0] = p.get_Point(0); this->_point[1] = p.get_Point(1); this->_point[2] = p.get_Point(2);

}

bool Primitive::operator==(Primitive p) {
	if (this->_point[0] == p.get_Point(0) && this->_point[1] == p.get_Point(1) && this->_point[2] == p.get_Point(2)) return true; else return false;

}

void Primitive::operator+=(Primitive p) {
	this->_point[0] = this->_point[0] + p.get_Point(0); this->_point[1] = this->_point[1] + p.get_Point(1); this->_point[2] = this->_point[2] + p.get_Point(2);

}
void Primitive::operator-=(Primitive p) {
	this->_point[0] = this->_point[0] - p.get_Point(0); this->_point[1] = this->_point[1] - p.get_Point(1); this->_point[2] = this->_point[2] - p.get_Point(2);

}
void Primitive::operator*=(Primitive p) {
	this->_point[0] = this->_point[0] * p.get_Point(0); this->_point[1] = this->_point[1] * p.get_Point(1); this->_point[2] = this->_point[2] * p.get_Point(2);

}
void Primitive::operator/=(Primitive p) {
	this->_point[0] = this->_point[0] / p.get_Point(0); this->_point[1] = this->_point[1] / p.get_Point(1); this->_point[2] = this->_point[2] / p.get_Point(2);

}

Primitive Primitive::operator+(Primitive p) {
	return Primitive(this->_point[0] + p.get_Point(0), this->_point[1] + p.get_Point(1), this->_point[2] + p.get_Point(2));

}
Primitive Primitive::operator-(Primitive p) {
	return Primitive(this->_point[0] - p.get_Point(0), this->_point[1] - p.get_Point(1), this->_point[2] - p.get_Point(2));

}
Primitive Primitive::operator*(Primitive p) {
	return Primitive(this->_point[0] * p.get_Point(0), this->_point[1] * p.get_Point(1), this->_point[2] * p.get_Point(2));

}
Primitive Primitive::operator/(Primitive p) {
	return Primitive(this->_point[0] / p.get_Point(0), this->_point[1] / p.get_Point(1), this->_point[2] / p.get_Point(2));

}

