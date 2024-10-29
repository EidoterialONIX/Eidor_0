#include "color.h"

Color::Color(
	GLuint r, GLuint g,
	GLuint b, GLuint a
) {
	this->set_Color(
		r, g,
		b, a
	);

}

void Color::set_Color(
	GLuint r, GLuint g,
	GLuint b, GLuint a
) {
	this->_r = r; this->_g = g;
	this->_b = b; this->_a = a;

	if (this->_r > 255) this->_r = 255;
	if (this->_g > 255) this->_g = 255;
	if (this->_b > 255) this->_b = 255;
	if (this->_a > 255) this->_a = 255;

}

GLfloat Color::pull_Color(GLuint index) const {
	
	if (index == 0) return this->_r / 255.f;
	else if (index == 1) return this->_g / 255.f;
	else if (index == 2) return this->_b / 255.f;
	else if (index == 3) return this->_a / 255.f;
	
}

void Color::out_Information() const {
	using namespace std;

	cout
		<< "RED: "
		<< this->_r
		<< "| GREEN: "
		<< this->_g
		<< "| BLUE: "
		<< this->_b
		<< "| ALPFA: "
		<< this->_a
		<< endl;

}

void Color::operator=(Color c) {
	this->set_Color(
		c._r, c._g,
		c._b, c._a
	);

}

bool Color::operator==(Color c) {
	if (this->_r == c._r && this->_g == c._g &&
		this->_b == c._b && this->_a == c._a) return true;
	else return false;

}

void Color::operator+=(Color c) {
	this->set_Color(
		this->_r + c._r, this->_g + c._g,
		this->_b + c._b, this->_a + c._a
	);

}

void Color::operator-=(Color c) {
	this->set_Color(
		this->_r - c._r, this->_g - c._g,
		this->_b - c._b, this->_a - c._a
	);

}

void Color::operator*=(Color c) {
	this->set_Color(
		this->_r * c._r, this->_g * c._g,
		this->_b * c._b, this->_a * c._a
	);

}

void Color::operator/=(Color c) {
	this->set_Color(
		std::round(this->_r / c._r), std::round(this->_g / c._g),
		std::round(this->_b / c._b), std::round(this->_a / c._a)
	);

}

Color Color::operator+(Color c) {
	return Color(
		this->_r + c._r, this->_g + c._g,
		this->_b + c._b, this->_a + c._a
	);

}

Color Color::operator-(Color c) {
	return Color(
		this->_r - c._r, this->_g - c._g,
		this->_b - c._b, this->_a - c._a
	);

}


Color Color::operator*(Color c) {
	return Color(
		this->_r * c._r, this->_g * c._g,
		this->_b * c._b, this->_a * c._a
	);

}

Color Color::operator/(Color c) {
	return Color(
		std::round(this->_r / c._r), std::round(this->_g / c._g),
		std::round(this->_b / c._b), std::round(this->_a / c._a)
	);

}