#include "primitive.h"

Primitive::Primitive(
	Vector3D_f point_0,
	Vector3D_f point_1,
	Vector3D_f point_2
) {
	this->set_Primitive(
		point_0,
		point_1,
		point_2
	);

}

void Primitive::set_Primitive(
	Vector3D_f point_0,
	Vector3D_f point_1,
	Vector3D_f point_2
) {
	this->_point_0 = point_0;
	this->_point_1 = point_1;
	this->_point_2 = point_2;

}

Vector3D_f* Primitive::pull_Primitive() const {
	Vector3D_f primitive[3] = {
		Vector3D_f(0.0f, 0.0f, 0.0f),
		Vector3D_f(0.0f, 0.0f, 0.0f),
		Vector3D_f(0.0f, 0.0f, 0.0f)
	};

	primitive[0] = this->_point_0;
	primitive[1] = this->_point_1;
	primitive[2] = this->_point_2;

	return primitive;

}

void Primitive::out_Information() const {
	using namespace std;

	cout
		<< "Point "
		<< 0
		<< ": "
		<< "( X: "
		<< this->_point_0.x
		<< ", Y: "
		<< this->_point_0.y
		<< ", Z: "
		<< this->_point_0.z
		<< " )"
		<< endl;
	cout
		<< "Point "
		<< 1
		<< ": "
		<< "( X: "
		<< this->_point_1.x
		<< ", Y: "
		<< this->_point_1.y
		<< ", Z: "
		<< this->_point_1.z
		<< " )"
		<< endl;
	cout
		<< "Point "
		<< 2
		<< ": "
		<< "( X: "
		<< this->_point_2.x
		<< ", Y: "
		<< this->_point_2.y
		<< ", Z: "
		<< this->_point_2.z
		<< " )"
		<< endl;

}

void Primitive::operator=(Primitive p) {
	this->set_Primitive(
		p._point_0,
		p._point_1,
		p._point_2
	);

}

bool Primitive::operator==(Primitive p) {
	if (this->_point_0 == p._point_0 &&
		this->_point_1 == p._point_1 &&
		this->_point_2 == p._point_2) return true;
	else return false;

}

void Primitive::operator+=(Primitive p) {
	this->set_Primitive(
		this->_point_0 + p._point_0,
		this->_point_1 + p._point_1,
		this->_point_2 + p._point_2
	);

}
void Primitive::operator-=(Primitive p) {
	this->set_Primitive(
		this->_point_0 - p._point_0,
		this->_point_1 - p._point_1,
		this->_point_2 - p._point_2
	);

}
void Primitive::operator*=(Primitive p) {
	this->set_Primitive(
		this->_point_0 * p._point_0,
		this->_point_1 * p._point_1,
		this->_point_2 * p._point_2
	);

}
void Primitive::operator/=(Primitive p) {
	this->set_Primitive(
		this->_point_0 / p._point_0,
		this->_point_1 / p._point_1,
		this->_point_2 / p._point_2
	);

}

Primitive Primitive::operator+(Primitive p) {
	return Primitive(
		this->_point_0 + p._point_0,
		this->_point_1 + p._point_1,
		this->_point_2 + p._point_2
	);

}
Primitive Primitive::operator-(Primitive p) {
	return Primitive(
		this->_point_0 - p._point_0,
		this->_point_1 - p._point_1,
		this->_point_2 - p._point_2
	);

}
Primitive Primitive::operator*(Primitive p) {
	return Primitive(
		this->_point_0 * p._point_0,
		this->_point_1 * p._point_1,
		this->_point_2 * p._point_2
	);

}
Primitive Primitive::operator/(Primitive p) {
	return Primitive(
		this->_point_0 / p._point_0,
		this->_point_1 / p._point_1,
		this->_point_2 / p._point_2
	);

}

