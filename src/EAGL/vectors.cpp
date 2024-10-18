#include "vectors.h"





/// VECTOR2D_F
/// //////////

Vector2D_f::Vector2D_f(float x, float y) {
	this->x = x; this->y = y;
	
}

void Vector2D_f::operator=(Vector2D_f v) {
	this->x = v.x; this->y = v.y;
	
}

bool Vector2D_f::operator==(Vector2D_f v) {
	if (this->x == v.x && this->y == v.y) return true;  else false;

}

void Vector2D_f::operator+=(Vector2D_f v) {
	this->x = this->x + v.x; this->y = this->y + v.y;

}
void Vector2D_f::operator-=(Vector2D_f v) {
	this->x = this->x - v.x; this->y = this->y - v.y;

}
void Vector2D_f::operator*=(Vector2D_f v) {
	this->x = this->x * v.x; this->y = this->y * v.y;

}
void Vector2D_f::operator/=(Vector2D_f v) {
	this->x = this->x / v.x; this->y = this->y / v.y;

}

Vector2D_f Vector2D_f::operator+(Vector2D_f v) {
	return Vector2D_f(this->x + v.x, this->y + v.y);

}
Vector2D_f Vector2D_f::operator-(Vector2D_f v) {
	return Vector2D_f(this->x - v.x, this->y - v.y);

}
Vector2D_f Vector2D_f::operator*(Vector2D_f v) {
	return Vector2D_f(this->x * v.x, this->y * v.y);

}
Vector2D_f Vector2D_f::operator/(Vector2D_f v) {
	return Vector2D_f(this->x / v.x, this->y / v.y);

}

/// //////////


/// VECTOR2D_I
/// //////////

Vector2D_i::Vector2D_i(int x, int y) {
	this->x = x; this->y = y;

}

void Vector2D_i::operator=(Vector2D_i v) {
	this->x = v.x; this->y = v.y;

}

bool Vector2D_i::operator==(Vector2D_i v) {
	if (this->x == v.x && this->y == v.y) return true;  else false;

}

void Vector2D_i::operator+=(Vector2D_i v) {
	this->x = this->x + v.x; this->y = this->y + v.y;

}
void Vector2D_i::operator-=(Vector2D_i v) {
	this->x = this->x - v.x; this->y = this->y - v.y;

}
void Vector2D_i::operator*=(Vector2D_i v) {
	this->x = this->x * v.x; this->y = this->y * v.y;

}
void Vector2D_i::operator/=(Vector2D_i v) {
	this->x = this->x / v.x; this->y = this->y / v.y;

}

Vector2D_i Vector2D_i::operator+(Vector2D_i v) {
	return Vector2D_i(this->x + v.x, this->y + v.y);

}
Vector2D_i Vector2D_i::operator-(Vector2D_i v) {
	return Vector2D_i(this->x - v.x, this->y - v.y);

}
Vector2D_i Vector2D_i::operator*(Vector2D_i v) {
	return Vector2D_i(this->x * v.x, this->y * v.y);

}
Vector2D_i Vector2D_i::operator/(Vector2D_i v) {
	return Vector2D_i(this->x / v.x, this->y / v.y);

}

/// //////////


/// VECTOR3D_F
/// //////////

Vector3D_f::Vector3D_f(float x, float y, float z) {
	this->x = x; this->y = y; this->z = z;

}

Vector3D_f::Vector3D_f(Vector2D_f v, float z) {
	this->x = v.x; this->y = v.y; this->z = z;

}

void Vector3D_f::operator=(Vector3D_f v) {
	this->x = v.x; this->y = v.y; this->z = v.z;

}

bool Vector3D_f::operator==(Vector3D_f v) {
	if (this->x == v.x && this->y == v.y && this->z == v.z) return true;  else false;

}

void Vector3D_f::operator+=(Vector3D_f v) {
	this->x = this->x + v.x; this->y = this->y + v.y; this->z = this->z + v.z;

}
void Vector3D_f::operator-=(Vector3D_f v) {
	this->x = this->x - v.x; this->y = this->y - v.y; this->z = this->z - v.z;

}
void Vector3D_f::operator*=(Vector3D_f v) {
	this->x = this->x * v.x; this->y = this->y * v.y; this->z = this->z * v.z;

}
void Vector3D_f::operator/=(Vector3D_f v) {
	this->x = this->x / v.x; this->y = this->y / v.y; this->z = this->z / v.z;

}

Vector3D_f Vector3D_f::operator+(Vector3D_f v) {
	return Vector3D_f(this->x + v.x, this->y + v.y, this->z + v.z);

}
Vector3D_f Vector3D_f::operator-(Vector3D_f v) {
	return Vector3D_f(this->x - v.x, this->y - v.y, this->z - v.z);

}
Vector3D_f Vector3D_f::operator*(Vector3D_f v) {
	return Vector3D_f(this->x * v.x, this->y * v.y, this->z * v.z);

}
Vector3D_f Vector3D_f::operator/(Vector3D_f v) {
	return Vector3D_f(this->x / v.x, this->y / v.y, this->z / v.z);

}

/// //////////



